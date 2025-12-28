/*
 * ttt.c
 *
 * Terminal-based Tic-Tac-Toe game.
 * Computer opponent selects moves using a simple priority system:
 *   1. Complete a winning line if possible.
 *   2. Block the player from winning.
 *   3. Take remaining spaces based on the player's moves.
 *
 * Author: Bryan C.
 * Date: December 26, 2025
 */

#include <stdio.h>

#define SIZE        3
#define PATTERNS    8
#define BOARD_SIZE  9
#define MIN_MOVE    1
#define PLAYER_X   'X'
#define PLAYER_O   'O'
#define EMPTY       0

typedef struct {
    int row;
    int col;
} Coord;

/* all 8 possible winning patterns */
Coord lines[PATTERNS][SIZE] = {
    {{0,0},{0,1},{0,2}},  /* pattern 0: top row */
    {{1,0},{1,1},{1,2}},  /* pattern 1: middle row */
    {{2,0},{2,1},{2,2}},  /* pattern 2: bottom row */
    {{0,0},{1,0},{2,0}},  /* pattern 3: left column */
    {{0,1},{1,1},{2,1}},  /* pattern 4: middle column */
    {{0,2},{1,2},{2,2}},  /* pattern 5: right column */
    {{0,0},{1,1},{2,2}},  /* pattern 6: diagonal TL–BR */
    {{0,2},{1,1},{2,0}}   /* pattern 7: diagonal TR–BL */
};

void draw_board(char (*board)[SIZE]);
void game_loop(char (*board)[SIZE]);
int check_winner(char (*board)[SIZE]);

int main(void)
{
    int c = 1;
    char board[SIZE][SIZE];  /* 3x3 tic-tac-toe board */
    
    printf("Tic-Tac-Toe\n\n");

    /* populate game board with numbers for selection (1-9) */
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = c++ + '0';
        }
    }

    draw_board(board);
    game_loop(board);

    return 0;
}

/* draw_board: draw and update the game board */
void draw_board(char (*board)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            putchar(board[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}

/* game_loop: game logic loop */
void game_loop(char (*board)[SIZE])
{
    int n;
    int row, col;
    int moves = 0;
    char turn = PLAYER_X;  /* X goes first */

    while (moves < BOARD_SIZE)
    {
        if (turn == PLAYER_X)  /* player turn (X) */
        {
            do
            {
                printf("\nPlayer move: ");
                if (scanf("%d", &n) != 1 || n < MIN_MOVE || n > BOARD_SIZE)
                {
                    while (getchar() != '\n')
                        ;
                    n = 0;
                }
            } 
            while (n <= 0);

            /*
             * Calculate position on board based on number entered:
             * row will always be 0 - 2 due to integer division (0-8 / 3)
             * col will be determined by remainder of integer division
             */
            row = (n - 1) / SIZE;
            col = (n - 1) % SIZE;

            if (board[row][col] != PLAYER_X && board[row][col] != PLAYER_O)
            {
                board[row][col] = PLAYER_X;
                moves++;
                draw_board(board);

                int winner = check_winner(board);
                if (winner)
                {
                    printf("\n%c wins!\n", winner);
                    break;
                }
                if (moves == BOARD_SIZE)
                {
                    printf("\nDraw!\n");
                    break;
                }
                turn = PLAYER_O;
            }
        }
        if (turn == PLAYER_O)  /* computer turn (O) */
        {
            int b = 0;         /* count blanks */
            int o = 0;         /* count Os */
            int x = 0;         /* count Xs */
            int fork = 0;      /* player occupies opposite corners (value: 1) */
            int complete = 0;  /* computer move complete (value: 1) */
            int empty_row = -1;
            int empty_col = -1;

            /*
             * Complete a potential win or block a player win:
             * - Examine each winning pattern (row, column, or diagonal).
             * - Count Xs, Os, and empty squares in the pattern.
             * - Record the empty position for a possible winning or blocking move.
             *
             * lines[i]     : one complete winning pattern (row, column, or diagonal).
             * lines[i][j]  : one board position within that pattern.
             *
             * Outer loop iterates lines[i] through all 8 winning patterns.
             * Inner loop iterates lines[i][j] through the 3 positions of current pattern.
             */
            printf("\nComputer move:\n");
            for (int i = 0; i < PATTERNS; i++)
            {
                x = o = b = 0;
                empty_row = empty_col = -1;
                for (int j = 0; j < SIZE; j++)
                {
                    int r = lines[i][j].row;
                    int c = lines[i][j].col;
                    if (board[r][c] == PLAYER_X)
                    {
                        x++;
                    }
                    else if (board[r][c] == PLAYER_O)
                    {
                        o++;
                    }
                    else
                    {
                        b++;
                        empty_row = r;
                        empty_col = c;
                    }
                }
                if (o == 2 && b == 1)
                {
                    board[empty_row][empty_col] = PLAYER_O;
                    complete = 1;
                    break;
                }
                else if (x == 2 && b == 1)
                {
                    board[empty_row][empty_col] = PLAYER_O;
                    complete = 1;
                    break;
                }
            }

            /*
             * Computer move priorities (if no block or win is possible):
             * 1. Take center space if free.
             * 2. If the player occupies two opposite corners (fork) take edge spaces.
             * 3. Otherwise, take available corners in this order: TL, BR, TR, BL.
             * 4. Take the next available empty space.
             */
            if ((board[0][0] == PLAYER_X && board[2][2] == PLAYER_X) ||
                (board[0][2] == PLAYER_X && board[2][0] == PLAYER_X))
            {
                fork = 1;
            }
            if (!complete && board[1][1] != PLAYER_X && board[1][1] != PLAYER_O)
            {
                board[1][1] = PLAYER_O;  /* center */
                complete = 1;
            }
            else if (!complete && !fork && board[0][0] != PLAYER_X && board[0][0] != PLAYER_O)
            {
                board[0][0] = PLAYER_O;  /* TL */
                complete = 1;
            }
            else if (!complete && !fork && board[2][2] != PLAYER_X && board[2][2] != PLAYER_O)
            {
                board[2][2] = PLAYER_O;  /* BR */
                complete = 1;
            }
            else if (!complete && !fork && board[0][2] != PLAYER_X && board[0][2] != PLAYER_O)
            {
                board[0][2] = PLAYER_O;  /* TR */
                complete = 1;
            }
            else if (!complete && !fork && board[2][0] != PLAYER_X && board[2][0] != PLAYER_O)
            {
                board[2][0] = PLAYER_O;  /* BL */
                complete = 1;
            }
            else if (!complete && fork && board[0][1] != PLAYER_X && board[0][1] != PLAYER_O)
            {
                board[0][1] = PLAYER_O;  /* TC */
                complete = 1;
            }
            else if (!complete && fork && board[1][0] != PLAYER_X && board[1][0] != PLAYER_O)
            {
                board[1][0] = PLAYER_O;  /* LC */
                complete = 1;
            }
            else if (!complete && fork && board[2][1] != PLAYER_X && board[2][1] != PLAYER_O)
            {
                board[2][1] = PLAYER_O;  /* BC */
                complete = 1;
            }
            else if (!complete && fork && board[1][2] != PLAYER_X && board[1][2] != PLAYER_O)
            {
                board[1][2] = PLAYER_O;  /* RC */
                complete = 1;
            }
            else  /* take first available empty space */
            {
                for (int i = 0; i < SIZE && !complete; i++)
                {
                    for (int j = 0; j < SIZE && !complete; j++)
                    {
                        if (board[i][j] != PLAYER_X && board[i][j] != PLAYER_O)
                        {
                            board[i][j] = PLAYER_O;
                            complete = 1;
                        }
                    }
                }
            }
            moves++;
            draw_board(board);

            int winner = check_winner(board);
            if (winner)
            {
                printf("\n%c wins!\n", winner);
                break;
            }
            if (moves == BOARD_SIZE)
            {
                printf("\nDraw!\n");
                break;
            }
            turn = PLAYER_X;
        }
    }
}

/* check_winner: check for a win */
int check_winner(char (*board)[SIZE])
{
    for (int i = 0; i < PATTERNS; i++)
    {
        char symbol = board[lines[i][0].row][lines[i][0].col];

        /* only consider lines starting with a valid player mark */
        if (symbol == PLAYER_X || symbol == PLAYER_O)
        {
            if (symbol == board[lines[i][1].row][lines[i][1].col] &&
                symbol == board[lines[i][2].row][lines[i][2].col])
            {
                return symbol;
            }
        }
    }
    return EMPTY;
}
