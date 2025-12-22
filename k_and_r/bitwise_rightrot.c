/*
 * Exercise 2-8
 * Return the value of the integer x rotated to the right by n bit positions
 * x = 10110010
 * n = 3
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
    unsigned x = 0b10110010;  /* 178 */
    int n = 3;
    unsigned result = rightrot(x, n);

    printf("%u\n", result);  /* prints 86 (binary 01010110) */

    return 0;
}

unsigned rightrot(unsigned x, int n) {
    /* treat x as an 8-bit number for rotation */
    int w = 8;

    /* handle cases where n >= 8 by taking remainder */
    n = n % w;

    /* if n is 0, no rotation needed; return x unchanged */
    if (n == 0) return x;

    /*
     * extract the rightmost n bits of x
     * mask with ~(~0 << n) produces n 1's in the rightmost positions
     * e.g., n=3 → mask = 00000111
     */
    unsigned lower = x & ~(~0 << n);

    /*
     * shift x right by n bits (dropping rightmost n bits)
     * shift the extracted rightmost n bits (lower) left to wrap them around to the beginning
     * OR both parts together to produce the final rotated value.
     * Example: x = 10110010, n = 3
     * x >> 3      = 00010110 (10110010 becomes 00010110)
     * lower << 5  = 01000000 (shift 101 5 spaces left to beginning)
     * OR result   = 01010110 (combine)
     */
    return (x >> n) | (lower << (w - n));
}
