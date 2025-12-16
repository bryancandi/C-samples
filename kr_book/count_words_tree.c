/*
 * Sample 6.5
 * Self-referential Structures
 * Word frequency count
 * To-do: Implement exercises 6-3 and 6-4
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {            /* the tree node */
    char *word;           /* points to the text */
    int count;            /* number of occurrences */
    struct tnode *left;   /* left child */
    struct tnode *right;  /* right child */
};

#define MAXWORD 100
#define BUFSIZE 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *my_strdup(char *);
void freetree(struct tnode *);
int getword(char*, int);

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    freetree(root);
    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)  /* a new word has arrived */
    {
        p = talloc();  /* make a new node */
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;  /* repeat word */
    }
    else if (cond < 0)  /* less than into left subtree */
    {
        p->left = addtree(p->left, w);
    }
    else  /* greater than into right subtree */
    {
        p->right  = addtree(p->right, w);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* my_strdup: make c duplicate of s (renamed from strdup to avoid string.h confict) */
char *my_strdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);  /* +1 for '\0' */
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
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
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
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
