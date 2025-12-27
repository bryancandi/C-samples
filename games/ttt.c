/*
 * ttt.c
 *
 * Tic-Tac-Toe
 * Author: Bryan C.
 * Date: December 26, 2025
 */

#include <ctype.h>
#include <stdio.h>

#define SIZE        3
#define PATTERNS    8
#define BOARD_SIZE  9
#define NO_WINNER   0

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

void draw_board(char[SIZE][SIZE]);
int check_winner(char[SIZE][SIZE]);

int main(void)
{
    int c = 1;
    int n;
    int row, col;
    int moves = 0;
    char turn = 'X';         /* starting player X */
    char board[SIZE][SIZE];  /* 3x3 tic-tac-toe board */
    
    printf("Tic-tac-toe\n\n");

    /* populate game board with numbers for selection (1-9) */
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = c++ + '0';
        }
    }
    draw_board(board);

    while (moves < BOARD_SIZE)
    {
        if (turn == 'X')  /* player turn */
        {
            do
            {
                printf("\nPlayer move: ");
                if (scanf("%d", &n) != 1 || n < 1)
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

            if (board[row][col] != 'X' && board[row][col] != 'O')
            {
                board[row][col] = 'X';
                moves++;
                draw_board(board);

                if (moves == BOARD_SIZE)
                {
                    printf("\nDraw!\n");
                    break;
                }
                if (check_winner(board) == 'X')
                {
                    printf("\nX wins!\n");
                    break;
                }
                else if (check_winner(board) == 'O')
                {
                    printf("\nO Wins!\n");
                    break;
                }
                turn = 'O';
            }
        }
        if (turn == 'O')  /* computer turn */
        {
            int x = 0;  /* Xs */
            int b = 0;  /* blanks */
            int done = 0;
            int empty_row = -1;
            int empty_col = -1;

            /*
             * Block possible win by player.
             * Examine one winning pattern at a time:
             * count Xs, count empty squares,
             * record the empty position for a possible blocking move.
             *
             * lines[i]     : one complete winning pattern (row, column, or diagonal)
             * lines[i][j]  : one board position within that pattern
             *
             * The outer loop increments lines[i] through all 8 possible win conditions.
             * The inner loop increments lines[i][j] through the 3 board positions
             * that must match for a win.
             */
            printf("\nComputer move:\n");
            for (int i = 0; i < PATTERNS; i++)
            {
                x = b = 0;
                empty_row = empty_col = -1;
                for (int j = 0; j < SIZE; j++)
                {
                    int r = lines[i][j].row;
                    int c = lines[i][j].col;
                    if (board[r][c] == 'X')
                    {
                        x++;
                    }
                    else if (board[r][c] != 'O')
                    {
                        b++;
                        empty_row = r;
                        empty_col = c;
                    }
                }
                if (x == 2 && b == 1)
                {
                    board[empty_row][empty_col] = 'O';
                    done = 1;
                    break;
                }
            }

            /*
             * Computer move priorities (if no block):
             * 1. Take center if free
             * 2. Take available corners in this order: TL, TR, BL, BR
             * 3. Take the next empty square
             */
            if (!done && board[1][1] != 'X' && board[1][1] != 'O')
            {
                board[1][1] = 'O';  /* center */
                done = 1;
            }
            else if(!done && board[0][0] != 'X' && board[0][0] != 'O')
            {
                board[0][0] = 'O';  /* TL */
                done = 1;
            }
            else if(!done && board[0][2] != 'X' && board[0][2] != 'O')
            {
                board[0][2] = 'O';  /* TR */
                done = 1;
            }
            else if(!done && board[2][0] != 'X' && board[2][0] != 'O')
            {
                board[2][0] = 'O';  /* BL */
                done = 1;
            }
            else if(!done && board[2][2] != 'X' && board[2][2] != 'O')
            {
                board[2][2] = 'O';  /* BR */
                done = 1;
            }
            else  /* take first available empty space */
            {
                for (int i = 0; i < SIZE && !done; i++)
                {
                    for (int j = 0; j < SIZE && !done; j++)
                    {
                        if (board[i][j] != 'X' && board[i][j] != 'O')
                        {
                            board[i][j] = 'O';
                            done = 1;
                        }
                    }
                }
            }
            moves++;
            draw_board(board);

            if (moves == BOARD_SIZE)
            {
                printf("\nDraw!\n");
                break;
            }
            if (check_winner(board) == 'X')
            {
                printf("\nX wins!\n");
                break;
            }
            else if (check_winner(board) == 'O')
            {
                printf("\nO wins!\n");
                break;
            }
            turn = 'X';
        }
    }
    return 0;
}

/* draw_board: draw and update the game board */
void draw_board(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}

/* check_winner: check for a win */
int check_winner(char board[SIZE][SIZE])
{
    for (int i = 0; i < PATTERNS; i++)
    {
        char symbol = board[lines[i][0].row][lines[i][0].col];

        /* only consider lines starting with a valid player mark */
        if (symbol == 'X' || symbol == 'O')
        {
                if (symbol == board[lines[i][1].row][lines[i][1].col] &&
                    symbol == board[lines[i][2].row][lines[i][2].col])
            {
                return symbol;
            }
        }
    }
    return NO_WINNER;
}
