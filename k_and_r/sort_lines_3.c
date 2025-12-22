/*
 * Sample 5.11
 * sort: sort input lines
 * optional flag:
 * -n   numeric sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000             /* max # lines to be sorted */
#define MAXLEN 1000               /* max length of any input line */
#define ALLOCSIZE 1000            /* size of available space */
char *lineptr[MAXLINES];          /* pointers to text lines */
static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

int my_getline(char *, int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));
int numcmp(char *, char *);
char *alloc(int);

int main(int argc, char *argv[])
{
    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
    {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void **) lineptr, 0, nlines - 1,
         numeric ? (int (*)(void *, void *))numcmp
                 : (int (*)(void *, void *))strcmp);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

/* my_getline: read a line into s, return length; renamed from getline to avoid POSIX conflict */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';  /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

/* my_qsort: sort v[left]...v[right] into increasing order; renamed from qsort to avoid stdlib conflict */
void my_qsort(void *v[], int left, int right,
            int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
    {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0 )
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if ( v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* alloc: return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)  /* it fits */
    {
        allocp += n;
        return allocp - n;  /* old p */
    }
    else  /* not enough room */
    {
        return 0;
    }
}
