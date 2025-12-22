/*
 * ascii.c
 * write ASCII character codes to stdout
 * terminate loop at 0 (ASCII NUL)
 */

#include <stdio.h>

int main(void)
{
    int ascii[] = {72, 69, 76, 76, 79, 33, 10, 0};

    int *p = ascii;

    while (*p != 0)
        putchar(*p++);

    return 0;
}
