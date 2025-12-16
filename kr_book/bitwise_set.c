/*
 * Exercise 2-6
 * Return x with the n bits that begin at position p set to the rightmost n bits of y
 * leaving the other bits unchanged.
 * In the example:
 * x = 10101100
 * y = 00000111
 * n = 3, p = 4
 * 
 * 3 (n) bits at position 4 (p) in x 101(011)00
 * position 4 from right to left:        ^
 * replace bits in x with rightmost 3 (n) bits of y 00000(111)
 * result: x is now: 101(111)00
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    unsigned x = 0b10101100;  /* 172 */
    unsigned y = 0b00000111;  /* 7 */
    int p = 4;
    int n = 3;
    unsigned result = setbits(x, p, n, y);

    printf("%u\n", result);  /* prints 188 (binary 10111100) */

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /*
     * create a mask with the rightmost n bits set to 1
     * 1. ~0 produces all 1’s in binary
     * 2. << n shifts those 1’s left by n, making the rightmost n bits 0
     * 3. ~ inverts the result, turning those rightmost n bits into 1’s
     * Example: n = 3 → mask = 00000111
     */
    unsigned mask = ~(~0 << n);

    /*
     * extract the rightmost n bits from y (using & mask, bitwise AND, only compare '1' bits)
     * then shift them into position so they align with bits p through p-(n-1) in x
     * << move the 3 bits over 2 spaces (4 + 1 - 3 = 2) will position them correctly
     */
    unsigned ybits = (y & mask) << (p + 1 - n);

    /*
     * clear (zero out) the n target bits in x by shifting the inverted mask into position
     * ~(mask << shift) ensures only those bits become 0; all others stay the same
     */
    unsigned xcleared = x & ~(mask << (p + 1 - n));

    /*
     * combine cleared x with shifted y bits (bitwise OR)
     * replaces x’s target bits with y’s extracted bits
     * visual: x = xxx(---)xx → xxx(yyy)xx
     *             765(432)10
     */
    return xcleared | ybits;
}
