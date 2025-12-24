/*
 * binary.c
 *
 * Convert binary values to decimal and ASCII (when printable)
 * Usage: ./bindecode <binary>
 * Author: Bryan C.
 * Date: December 20, 2025
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <binary>\n", argv[0]);
        return 1;
    }

    char *end;
    long value = strtol(argv[1], &end, 2);

    if (*end != '\0')
    {
        fprintf(stderr, "Invalid binary number\n");
        return 1;
    }

    printf("Decimal: %ld\n", value);

    if (value >= 32 && value <= 126)
    {
        printf("ASCII: %c\n", (unsigned char)value);
    }
    else if (value >= 0 && value <= 31)
    {
        printf("ASCII: non-printable control character\n");
    }
    else
    {
        printf("ASCII: value out of range\n");
    }

    return 0;
}
