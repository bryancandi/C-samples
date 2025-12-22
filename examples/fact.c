/*
 * fact.c
 * Get factorial using recursion
 */

#include <ctype.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n;
    do
    {
        printf("Number: ");
        int scan = scanf("%i", &n);
        if (scan == 0)
        {
            /* Clear the input buffer with getchar() when the user enters invalid input */
            while (getchar() != '\n');
        }
    }
    while (n <= 0);

    printf("Factorial of %i is: %i\n", n, fact(n));

    return 0;
}

int fact(int n)
{
    /* Base case */
    if (n == 1)
    {
        return 1;
    }
    /* Recursive case */
    else
    {
        return n * fact(n - 1);
    }
}
