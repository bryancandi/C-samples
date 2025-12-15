/*
 * Sample 5.12
 * Exercise 5-19
 * undcl: convert word descriptions into declarations
 * example: x is a function returning a pointer to an array of pointers to functions returning char
 * can be expressed as: x () * [] * () char
 * which returns: char (*(*x())[])()
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100        /* maximum tokens */
#define BUFSIZE 100         /* buffer size for getch/ungetch */

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

int gettoken(void);
int nexttoken(void);
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char out[1000];             /* output string */
int prevtoken = NO;         /* there is no previous token */

int getch(void);
void ungetch(int c);
char buf[BUFSIZE];          /* buffer for ungetch */
int bufp = 0;               /* next free position in buf */

/* convert word descriptions into declarations */
int main(void)
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n' && type != ';')
        {
            if (type == PARENS || type == BRACKETS)
            {
                strcat(out, token);
            }
            else if (type == '*')
            {
                int next = nexttoken();
                if (next == PARENS || next == BRACKETS)
                {
                    sprintf(temp, "(*%s)", out);
                }
                else
                {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

/* gettoken: return next token */
int gettoken(void)
{
    int c;
    char *p = token;

    if (prevtoken == YES)
    {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '\n')
    {
        return tokentype = '\n';
    }
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        *p++ = '[';
        while ((c = getch()) != ']' && c != EOF && c != '\n')
        {
            *p++ = c;
        }
        if (c != ']')
        {
            printf("error: missing ]\n");
        }
        else
        {
            *p++ = ']';
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
        {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
}

/* nexttoken: get the next token and push it back */
int nexttoken(void)
{
    int type;

    type = gettoken();
    prevtoken = YES;
    return type;
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
