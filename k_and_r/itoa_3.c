/*
 * Exercise 3-5
 * itoa: convert the integer n into a base b character representation in the string s
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void itoa(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    int b = 16;  /* base 16 for hexadecimal */
    int n = 255;
    char s[BUFFER];

    itoa(n, s, b);
    printf("Int: %d\n", n);
    printf("Str in base %d: %s\n", b, s);  /* prints n converted to string s */

    return 0;
}

void itoa(int n, char s[], int b)
{
    int i, j, sign;

    if ((sign = n) < 0)  /* record sign; check if negative */
    {
        n = -n;  /* make n positive */
    }
    i = 0;
    do  /* generate digits in reverse order */
    {
        j = n % b;  /* convert n to base b / get next digit */
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);  /* divide by b and remove last digit */
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
