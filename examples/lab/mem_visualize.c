/*
 * Print the memory address of each element in the array.
 * Array elements are stored contiguously in memory.
 * Visualize: base + index * 4 (32-bit integers)
 */

#include <stdio.h>

int main(void)
{
    size_t int_size = sizeof(int);
    printf("Array elements are integers.\n"
           "Addresses are contiguous, spaced %zu bytes apart.\n\n",
           int_size);

    int array[] = {1, 2, 4, 8, 16, 32, 64, 128};

    /* How many elements are in the array? */
    size_t length = sizeof(array) / sizeof(array[0]);

    /* Print the index, value, memory address for each array element. */
    printf("idx : val : address\n");
    for (size_t i = 0; i < length; i++)
    {
        printf("%3zu : %3d : %p\n", i, array[i], (void *)&array[i]);
    }

    /* How much memory was used? */
    printf("\nArray memory usage: %zu bytes\n", sizeof(array)); 

    return 0;
}
