/*
 * Exercise 6-2
 * Read a C program and print each group of variables that contain
 * the same first num (default 6) characters and print them
 * in alphabetical order. num can be specified by command-line arg.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {            /* the tree node */
    char *word;           /* points to the text */
    int match;            /* match found */
    struct tnode *left;   /* left child */
    struct tnode *right;  /* right child */
};

#define MAXWORD 100
#define BUFSIZE 100
#define YES 1
#define NO 0

struct tnode *addtreex(struct tnode *, char *, int, int *);
int compare(char *, struct tnode *, int, int *);
void treexprint(struct tnode *);
struct tnode *talloc(void);
void freetree(struct tnode *);
int getword(char *, int);

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/*
 * print in alphabetical order each group of variable names
 * identical in the first num characters (default 6)
 */
int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;  /* YES if match was found */
    int num;  /* number of the first identical characters */

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]) && strlen(word) >= num)
        {
            root = addtreex(root, word, num, &found);
        }
        found = NO;
    }
    treexprint(root);
    freetree(root);
    return 0;
}

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
    int cond;

    if (p == NULL)  /* a new word has arrived */
    {
        p = talloc();  /* make a new node */
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, found)) < 0)
    {
        p->left = addtreex(p->left, w, num, found);
    }
    else if (cond > 0)
    {
        p->right = addtreex(p->right, w, num, found);
    }
    return p;
}

/* compare: compare words and update p->match */
int compare(char *s, struct tnode *p, int num, int *found)
{
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }
    if (i >= num)  /* identical in first num characters? */
    {
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
    if (p != NULL)
    {
        treexprint(p->left);
        if (p->match)
        {
            printf("%s\n", p->word);
        }
        treexprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* freetree: free allocated memory */
void freetree(struct tnode *p)
{
    if (p != NULL)
    {
        freetree(p->left);
        freetree(p->right);
        free(p->word);  /* free the duplicated string */
        free(p);  /* free the node itself */
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, next, getch(void);
    int newline = 0;
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
    {
        newline = (c == '\n');
    }
    if (c != EOF)
    {
        *w++ = c;
    }
    if (c == '/')  /* handle single-line comments */
    {
        next = getch();
        if (next == '/')
        {
            while (c != '\n' && c != EOF)
            {
                c = getch();
                newline = (c == '\n');
            }
            *w = '\0';
            return c;
        }
        if (next == '*')  /* handle multi-line comments */
        {
            int prev = 0;
            while ((c = getch()) != EOF)
            {
                if (prev == '*' && c == '/')
                {
                    break;  /* end of comment */
                }
                prev = c;
                newline = (c == '\n');
            }
        }
    }
    if (c == '"')  /* skip string literals */
    {
        next = getch();
        if (next == '\\')
        {
            getch();  /* skip escaped character */
        }
        while (next != '"' && next != EOF)
        {
            next = getch();
            newline = (next == '\n');
        }
        *w = '\0';
        return next;
    }
    if (c == '\'')  /* skip character constants */
    {
        next = getch();
        if (next == '\\')
        {
            getch();  /* skip escape char */
        }
        while (next != '\'' && next != EOF)
        {
            next = getch();
            newline = (next == '\n');
        }
        *w = '\0';
        return next;
    }
    if (c == '#' && newline)  /* skip preprocessor directives */
    {
        while (c != '\n' && c != EOF)
        {
            c = getch();
            newline = (c == '\n');
        }
        *w = '\0';
        return c;
    }
    if (!isalpha(c) && c != '_')  /* recognize _ in identifier names */
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
    {
        c = getch();
        if (!isalnum(c) && c != '_')
        {
            ungetch(c);
            break;
        }
        *w = c;
    }
    *w = '\0';
    return word[0];
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
