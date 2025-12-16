/*
 * Sample 4.10
 * qsort: sort v[left]...v[right] into increasing order using recursion
 */

#include <stdio.h>

void qsort(int v[], int left, int right);

int main(void)
{
    int nums[] = {4, 32, 1, 76, 44, 18, 27, 89};
    int n = sizeof(nums) / sizeof(nums[0]);

    qsort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        {               /* fewer than two elements */
            return;
        }
    swap(v, left, (left + right) / 2);   /* move partition elem */
    last = left;                         /* to v[0] */
    for (i = left + 1; i <= right; i++)  /* partition */
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);  /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
