/*
 * Sample 5.12
 * Exercise 5-18
 * dcl: parse a C declaration and convert to words
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100        /* maximum tokens */
#define BUFSIZE 100         /* buffer size for getch/ungetch */

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void printerr(char *msg);

int gettoken(void);
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1000];             /* output string */
int prevtoken = NO;         /* there is no previous token */

int getch(void);
void ungetch(int c);
char buf[BUFSIZE];          /* buffer for ungetch */
int bufp = 0;               /* next free position in buf */

/* convert declaration to words */
int main(void)
{
    while (gettoken() != EOF)   /* first token on line */
    {                           /* is the datatype */
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                  /* parse rest of the line */
        if (tokentype == ';')   /* accept optional semicolon */
        {
            tokentype = gettoken();
        }
        if (tokentype != '\n')
        {
            printf("syntax error\n");
        }
        if (name[0] == '\0')
        {
            printf("invalid declaration\n");
        }
        else
        {
            printf("%s: %s %s\n", name, out, datatype);
        }
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )  /* count *'s */
    {
        ns++;
    }
    dirdcl();
    while(ns-- > 0)
    {
        strcat(out, " pointer to");
    }
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(')  /* ( dcl ) */
    {
        dcl();
        if (tokentype != ')')
        {
            printerr("missing )\n");
        }
    }
    else if (tokentype == NAME)  /* variable name */
    {
        strcpy(name, token);
    }
    else
    {
        printerr("expected name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
        {
            strcat(out, " function returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/* printerr: handle errors */
void printerr(char *msg)
{
    printf("error: %s", msg);
    name[0] = '\0';
    prevtoken = YES;
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
            printerr("missing ]\n");
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
