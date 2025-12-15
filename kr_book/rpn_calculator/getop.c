/*
 * getop.c
 * Exercise 4-11: modify getop so that it doesn't need to use ungetch
 * get next operator or numeric operand
 */

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    static int lastc = 0;

    if (lastc == 0)
    {
        c = getchar();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getchar();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c;  /* not a number */
    }
    i = 0;
    if (isdigit(c))  /* collect integer part */
    {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }
    if (c == '.')  /* collect fraction part */
    {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        lastc = c;
    }
    return NUMBER;
}
