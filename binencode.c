/*
 * binencode.c
 * Convert input string ASCII character values to 8-bit binary
 * Usage: ./binencode <string>
 * Author: Bryan C.
 * Date: December 21, 2025
 */

#include <stdio.h>
#include <stdlib.h>

#define BITS  8   /* binary bit width */
#define SPACE 32  /* ASCII value for space character */

void itob(unsigned int n, int bits);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Usage: %s <string> [string ...]\n", argv[0]);
        return 1;
    }
    while (--argc > 0) {
        char *p = *++argv;

        while (*p != '\0') {
            unsigned char c =  (unsigned char)*p++;
            itob(c, BITS);
            putchar(' ');
        }

        if (argc > 1) {
            itob(SPACE, BITS);
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}

void itob(unsigned int n, int bits)
{
    unsigned int bit;

    if (bits == 0) {
        return;
    }

    bit = n & 1;
    itob(n >> 1, bits - 1);
    printf("%d", bit);
}
