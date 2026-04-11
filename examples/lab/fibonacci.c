/*
 * Print Fibonacci sequence with N terms (1–25).
 */

#include <stdio.h>

int main(void)
{
    int inp;
    int arr[25];

    printf("Enter a number (1 to 25): ");
    if (scanf("%d", &inp) != 1 || inp < 1 || inp > 25)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    arr[0] = arr[1] = 1;

    for (int i = 0; i < inp; i++)
    {
        if (i >= 2)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        printf("%d\n", arr[i]);
    }

    return 0;
}
