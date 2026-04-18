#include <stdio.h>

int main(void)
{
    int c = 1;
    int x = (c++) - 1;
    printf("%d\n", x);

    return 0;
}
