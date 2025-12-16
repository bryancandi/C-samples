/*
 * Sample 5.2
 * Simplified alternate version; no getch / ungetch
 * getint: get next integer from input into *pn
 */

#include <ctype.h>
#include <stdio.h>

int getint(int *pn);

int main(void)
{
    int n;

    if (getint(&n) != 0)  /* pass address of n into getint */
    {
        printf("%d\n", n);  /* print n directly modified by getint */
    }
    else
    {
        printf("Not a number\n");
    }

    return 0;
}

int getint(int *pn)  /* pn points to int where the parsed number will be stored */
{
    int c, sign;

    while (isspace(c = getchar()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar();
    }
    for (*pn = 0; isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    return c;
}
