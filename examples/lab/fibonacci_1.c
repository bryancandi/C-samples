/*
 * Print Fibonacci sequence up to Fn (0-93).
 */

#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t n1 = 0, n2 = 1, tmp;
    int count;

    printf("Enter a number (0 to 93): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 93)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    while(count >= 0)
    {
        printf("%zu\n", n1);
        tmp = n1;
        n1 = n1 + n2;
        n2 = tmp;
        count--;
    }

    return 0;
}
