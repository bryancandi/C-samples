/*
 * Exercise 4-12
 * itoa: convert n to characters in s using recursion
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    int n = -123;
    char s[BUFFER];

    itoa(n, s);
    printf("Int: %d\n", n);
    printf("Str: %s\n", s);  /* prints n converted to string s */

    return 0;
}

void itoa(int n, char s[])
{
    static int i = 0;  /* initialized once (static) */

    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
    {
        itoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
