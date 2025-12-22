/*
 * Section 2.10 example
 * bitcount: count 1 bits in x
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
    int b;
    /* Shift x right by 1, effectively examining each bit one by one from right to left */
    for (b = 0; x != 0; x >>= 1)
    {
        /* Check the least significant bit (LSB), if LSB is 1, increment b */
        if (x & 1)
        {
            b++;
        }
    }
    return b;
}
