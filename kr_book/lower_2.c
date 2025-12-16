/*
 * Exercise 2-10
 * lower v2: convert c to lower case (ASCII) using a conditional expression
 */

#include <stdio.h>

int lower(int c);

int main(void)
{
    int c;
    int lc;

    while ((c = getchar()) != EOF)
    {
        lc = lower(c);
        putchar(lc);
    }

    return 0;
}

/*
 *use conditional expression to:
 * converts an uppercase ASCII letter 'c' to lowercase using the formula c + 'a' - 'A'
 * otherwise returne unmodified
 */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
