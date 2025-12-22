/*
 * Sample 3.6
 * itoa: convert n to characters in s using a do-while loop
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
    int i, sign;

    if ((sign = n) < 0)  /* record sign; check if negative */
    {
        n = -n;  /* make n positive */
    }
    i = 0;
    do  /* generate digits in reverse order */
    {
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);  /* delete it */
    if (sign < 0)
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
