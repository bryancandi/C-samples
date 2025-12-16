/*
 * Sample 3.5
 * atoi v2: convert s to integer
 */

#include <stdio.h>
#include <ctype.h>

#define BUFFER 1000

int atoi(char s[]);

int main(void)
{
    int c;
    int i = 0;
    char s[BUFFER];

    while ((c = getchar())!= EOF && c != '\n' && i < BUFFER - 1)
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    printf("Str: %s\n", s);
    printf("Int: %i\n", atoi(s));

    return 0;
}

int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;   /* negative or not */
    if (s[i] == '+' || s[i] == '-')  /* skip sign */
    {
        i++;
    }
    for (n = 0; isdigit(s[i]); i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}
