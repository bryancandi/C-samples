/* Sample 3.3 */

#include <stdio.h>

#define NOT_FOUND -1

int binsearch(int x, int v[], int n);

int main(void)
{
    int x = 18;  /* searching for this */
    int num_array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(num_array) / sizeof(num_array[0]);

    if (binsearch(x, num_array, size) == NOT_FOUND)
    {
        printf("%d not found.\n", x);
    }
    else
    {
        printf("%d found.\n", x);
    }

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <=v[n - 1] (array must be sorted) */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else  /* match found */
        {
            return mid;
        }
    }
    return -1;  /* no match */
}
