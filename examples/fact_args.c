/*
 * fact_args.c
 *
 * Get factorial using recursion from argv[1]
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fact(unsigned long long n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./fact <number>\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            fprintf(stderr, "Please enter a number.\n");
            return 1;
        }
    }

    unsigned long long n = atoi(argv[1]);

    printf("%llu\n", fact(n));

    return 0;
}

unsigned long long fact(unsigned long long n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
