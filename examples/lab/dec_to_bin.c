/*
 * Convert a positive decimal number to binary.
 *
 * Algorithm:
 *  1. If the starting number is even, emit 0. If it is odd, emit 1.
 *  2. Divide the current number by 2, discarding any remainder.
 *  3. If the quotient is 0, the algorithm is complete.
 *  4. If the quotient is not 0, prepend the current binary string with
 *     0 if the quotient is even, or 1 if the quotient is odd.
 *  5. Repeat from step 2 using the quotient as the current number.
 *
 * Note: This algorithm describes how to convert a decimal number to binary
 *       and may be implemented in different ways. This program appends the
 *       next binary digits to the current string, so the entire string is
 *       reversed before printing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [decimal]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // atoi returns 0 on error, so this is safe for now
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    else if (n < 0)
    {
        fprintf(stderr, "Please enter a positive decimal number.\n");
        return 1;
    }

    int j = sizeof(char) * 2;  // binary digit plus null terminator
    char *str = malloc(j);
    if (str == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int i = 0;
    for (; n != 0; n /= 2)
    {
        str[i++] = (n % 2) + '0';

        char *tmp = realloc(str, i + j);
        if (tmp == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            free(str);
            return 1;
        }
        str = tmp;
    }
    str[i] = '\0';

    strrev(str);  // TO-DO: replace for portability
    printf("%s", str);
    printf("\n");
    
    free(str);
    return 0;
}
