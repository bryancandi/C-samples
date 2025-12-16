/*
 * swap.c
 * swaps two integers using pointers
 */

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);  /* pass the address of x and y to the swap function */
    printf("x is %i, y is %i\n", x, y);

    return 0;
}

/* dereference with * */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
