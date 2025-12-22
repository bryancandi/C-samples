/*
 * Sample 5.6
 * sort: a simple line-sorting program using pointer arrays
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* main: max lines to be sorted */
#define MAXLEN 1000     /* readlines: max length of any input line */
#define ALLOCSIZE 1000  /* alloc: size of available space */

int my_getline(char *, int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);
char *alloc(int);

char *lineptr[MAXLINES];          /* pointers to text lines */
static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

int main(void)
{
    int nlines;  /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
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

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)  /* do nothing if array contains fewer than two elements */
    {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);   /* sort elements < pivot */
    qsort(v, last + 1, right);  /* sort elements > pivot */
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

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
