/*
 * binencode.c
 * Convert input string ASCII character values to 8-bit binary
 * Usage: ./binencode <string>
 * Author: Bryan C.
 * Date: December 21, 2025
 */

#include <stdio.h>
#include <stdlib.h>

#define BITS 8

void itob(unsigned int n, int bits);

int main(int argc, char *argv[])
{
    unsigned int n;
    char *end;
    char *p = argv[1];

    if (argc == 1) {
        printf("Usage: %s <binary>\n", argv[0]);
        return 1;
    }

    while (*p != '\0') {
        unsigned char c =  (unsigned char)*p++;
        itob(c, BITS);
        putchar(' ');
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
