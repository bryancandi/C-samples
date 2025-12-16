/*
 * Exercise 5-2
 * getfloat: get next floating-point number from input into *pn
 */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100  /* buffer size for getch/ungetch */
char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

int getfloat(float *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
    float n;

    if (getfloat(&n) != 0)  /* pass address of n into getfloat */
    {
        printf("%f\n", n);  /* print n directly modified by getfloat */
    }
    else
    {
        printf("Not a number\n");
    }

    return 0;
}

int getfloat(float *pn)  /* pn points to float where the parsed number will be stored */
{
    int c, d, sign;
    float power;

    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);  /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        d = c;  /* save sign char in d */
        c = getch();
        if (!isdigit(c) && c != '.')  /* sign followed by a decimal point is valid only if a digit follows */
        {
            ungetch(c);  /* push back non-digit char */
            ungetch(d);  /* push back sign char */
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.')
    {
        d = c;
        c = getch();
        if (!isdigit(c))  /* no digits following decimal point */
        {
            ungetch(c);
            ungetch(d);
            return 0;
        }
    }
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
