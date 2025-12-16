/*
 * Sample 5.2
 * getint: get next integer from input into *pn
 */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100  /* buffer size for getch/ungetch */
char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

int getint(int *pn);
int getch(void);
void ungetch(int c);

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

    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
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
