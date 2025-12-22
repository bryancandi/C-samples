/*
 * Exercise 3-4
 * itoa: convert n to characters in s using a do-while loop
 * avoid overflow by taking the absolute value of each digit
 * and appending a '-' sign if n is negative
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000

void my_itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    int n = -123;
    char s[BUFFER];

    my_itoa(n, s);
    printf("Int: %d\n", n);
    printf("Str: %s\n", s);  /* prints n converted to string s */

    return 0;
}

void my_itoa(int n, char s[])
{
    int i, sign;

    sign = n;
    i = 0;
    do  /* generate digits in reverse order */
    {
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while ((n /= 10) != 0);  /* remove last digit */
    if (sign < 0)  /* if n is negative add the '-' sign to the result */
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
