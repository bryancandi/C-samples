/*
 * Sample 3.8
 * goto example function
 * goto and labels: not commonly used or necessary
 */

#include <stdio.h>

int f_goto(int a[], int b[], int n, int m);

int main(void)
{
    int result;
    int array_a[] = {1, 2, 3, 4};
    int array_b[] = {3, 6, 9, 12};
    int n = sizeof(array_a) / sizeof(array_a[0]);
    int m = sizeof(array_b) / sizeof(array_b[0]);

    result = f_goto(array_a, array_b, n, m);

    if (result)
    {
        printf("Match found.\n");
    }
    else
    {
        printf("No match found.\n");
    }

    return 0;
}

int f_goto(int a[], int b[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                goto found;  /* goto label 'found' */
            }
        }
    }
    return 0;  /* no match */

found:
    return 1;
}
