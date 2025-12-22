/*
 * Sample 2.7
 * lower: convert c to lower case (ASCII)
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
 * converts an uppercase ASCII letter 'c' to lowercase using the formula c + 'a' - 'A'
 * otherwise return unmodified
 */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}
