/*
 * ten_print.c
 *
 * C version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 *
 * Uses Unicode diagonal line characters to render the maze.
 * Includes a cross-platform millisecond delay macro, msleep().
 *
 * Author: Bryan C.
 * Date: December 23, 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define msleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define msleep(ms) usleep((ms) * 1000)  /* millisecond to microsecond */
#endif

#define CHAR1 "\u2571"
#define CHAR2 "\u2572"
#define DELAY 5  /* milliseconds */

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  /* Windows needs UTF-8 code page */
#endif

    srand((unsigned)time(NULL));

    for (;;) {
        printf("%s", (rand() % 2) ? CHAR1 : CHAR2);
        fflush(stdout);
        msleep(DELAY);
    }
}
