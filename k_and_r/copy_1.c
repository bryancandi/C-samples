/*
 * Sample 1.5
 * copy: version 1
 */

#include <stdio.h>

/* copy input to output until EOF */

int main(void)
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}
