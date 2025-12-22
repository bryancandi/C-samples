/*
 * Exercise 2-7
 * Return x with n bits that begin at position p inverted, leaving the others unchanged
 * 1 changed to 0 and vice versa
 * x = 10101100
 * n = 3, p = 4
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    unsigned x = 0b10101100;  /* 172 */
    int p = 4;
    int n = 3;
    unsigned result = invert(x, p, n);

    printf("%u\n", result);  /* prints 176 (binary 10110000) */

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    /*
     *create a mask with the rightmost n bits set to 1
     * 1. ~0 produces all 1’s in binary
     * 2. << n shifts those 1’s left by n, making the rightmost n bits 0
     * 3. ~ inverts the result, turning those rightmost n bits into 1’s
     * Example: n = 3 → mask = 00000111
     */
    unsigned mask = ~(~0 << n);

    /* shift mask into position (4 + 1 - 3 = 2) 2 spaces left */
    unsigned mask_shifted = mask << (p + 1 - n);

    /* using XOR invert those 3 bits in x */
    x = x ^ mask_shifted;

    return x;
}
