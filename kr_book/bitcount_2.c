/*
 * Exercise 2-9
 * bitcount v2: count 1 bits in x using faster method
 */

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned x = 0b10110010;

    int result = bitcount(x);

    printf("%d\n", result);  /* returns 4 as 10110010 has 4 bits */

    return 0;
}

/* count '1' bits in x */
int bitcount(unsigned x)
{
    int b = 0;
    /* While x is not 0; delete rightmost 1-bit and increment b */
    while (x != 0)
    {
        x &= (x - 1);  /* clear the rightmost 1-bit */
        b++;
    }
    return b;
}
