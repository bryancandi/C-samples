/*
 * ten-print.c
 *
 * C version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>

#define UNICODE_C 0x2570

int main(void)
{
    setlocale(LC_CTYPE, "");
    srand((unsigned)time(NULL));

    for (;;) {
        wchar_t c = UNICODE_C + ((rand() % 2) + 1);
        wprintf(L"%lc", c);
    }
}
