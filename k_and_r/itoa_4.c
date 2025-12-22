/*
 * Exercise 3-6
 * itoa: specify minimum width and pad output on the left with white space accordingly
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void)
{
    int n = -123;
    int w = 6;  /* minimum output width */
    char s[BUFFER];

    itoa(n, s, w);
    printf("Int: %d\n", n);
    printf("Str: \"%s\"\n", s);  /* prints n converted to string s (quotes to show width) */

    return 0;
}

void itoa(int n, char s[], int w)
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
    while (i < w)  /* insert white space */
    {
        s[i++] = ' ';
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
