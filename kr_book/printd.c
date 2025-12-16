/*
 * Sample 4.10 
 * printd: print n in decimal using recursion 
 */

#include <stdio.h>

void printd(int n);

int main(void)
{
    int i = 123;
    int j = -456;
    
    printd(i);
    putchar('\n');
    printd(j);
    putchar('\n');

    return 0;
}

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}
