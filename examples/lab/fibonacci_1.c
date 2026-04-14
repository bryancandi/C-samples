/*
 * Print Fibonacci sequence up to Fn (0-93).
 */

#include <stdio.h>

int main(void)
{
    size_t f1 = 0;
    size_t f2 = 1;
    size_t tmp;
    int count;

    printf("Enter a number (0 to 93): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 93)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    printf("0\n");

    while(count > 0)
    {
        tmp = f1;
        f1 = f1 + f2;
        f2 = tmp;

        count--;

        printf("%zu\n", f1);
    }

    return 0;
}
