/*
 * Sample 1.5
 * copy: version 2
 */

#include <stdio.h>

/* copy input to output until EOF */

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}
