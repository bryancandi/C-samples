/*
 * 10 PRINT (alternate version)
 *
 * C version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 *
 * Treats the string literal "/\\" as an array and prints a random index.
 *
 * Author: Bryan C.
 * Date: 2025-12-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    while(1) putchar("/\\"[rand() % 2]);
}
