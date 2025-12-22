/*
 * Exercise 4-14
 * swap(t, x, y): a macro that interchanges two arguments of type t
 * temp is defined as a temporary variable of type t
 */

#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main(void)
{
    int x = 4;
    int y = 8;

    printf("Pre-swap:\nx: %d\ny: %d\n", x, y);
    swap(int, x, y);
    printf("Post-swap:\nx: %d\ny: %d\n", x, y);

    return 0;
}
