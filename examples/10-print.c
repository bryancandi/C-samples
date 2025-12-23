/*
 * 10-print.c
 *
 * C version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define CHAR1 "\u2571"
#define CHAR2 "\u2572"

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Windows needs UTF-8 code page
#endif

    srand((unsigned)time(NULL));

    for (;;) {
        printf("%s", (rand() % 2) ? CHAR1 : CHAR2);
    }
}
