/*
 * Print memory address of each element in the array.
 * Array memory addresses are contiguous.
 */

#include <stdio.h>

int main(void)
{
    int array[] = {2, 4, 8, 16};

    /* How many elements in the array? */
    size_t length = sizeof(array) / sizeof(array[0]);

    printf("Array element addresses:\n");

    for (size_t i = 0; i < length; i++)
    {
        printf("%zu : %p\n", i, (void *)&array[i]);
    }

    size_t int_size = sizeof(int);
    printf("\nArray elements are integers.\n"
           "Addresses are contiguous, spaced %zu bytes apart.\n",
           int_size);

    return 0;
}
