/*
 * bindecode.c
 * Convert binary values to decimal and ASCII (when printable)
 * Usage: ./bindecode <binary>
 * Author: Bryan C.
 * Date: December 20, 2025
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 256

int main(int argc, char *argv[])
{
    int len = 0;
    int pos = 1;  /* first arg after prog name */
    long values[MAX_VALUES];

    if (argc == 1) {
        printf("Usage: %s <binary>\n", argv[0]);
        return 1;
    }

    while (--argc > 0 && len < MAX_VALUES) {
        char *end;
        long value = strtol(*++argv, &end, 2);

        if (*end != '\0') {
            fprintf(stderr, "Invalid binary number: %s at position %d\n", *argv, pos);
            return 1;
        }

        values[len++] = value;
        pos++;
    }

    printf("Decimal: ");
    for (int i = 0; i < len; i++) {
        printf("%ld ", values[i]);
    }

    printf("\nASCII: ");
    for (int i = 0; i < len; i++) {
        if (values[i] >= 32 && values[i] <= 126) {
            putchar(values[i]);
        }
    }
    putchar('\n');

    if (len == MAX_VALUES) {
        fprintf(stderr, "Buffer full (%d), additional arguments ignored.\n", MAX_VALUES);
    }

    return 0;
}
