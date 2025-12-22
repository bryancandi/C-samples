/*
 * prefix_postfix.c
 * Demonstration of post-increment/decrement (i++, i--) 
 * Versus pre-increment/decrement (++i, --i).
 */

#include <stdio.h>

void print_num(int n);

int main(void)
{
    int i;

    printf("i = 1\n\n");

    i = 1;
    printf("i++:  ");
    print_num(i++);  /* return current value of 'i', then increment */

    i = 1;
    printf("++i:  ");
    print_num(++i);  /* increment 'i', then return the new value */

    return 0;
}

void print_num(int n)
{
    printf("%d\n", n);
}
