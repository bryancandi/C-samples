/*
 * Exercise 5-17
 * sort: sort input lines
 * optional flags:
 * -n   numeric sort
 * -r   reverse sort order
 * -f   fold upper and lower case together (ignore case)
 * -d   directory order (compare only letters, numbers, and blanks)
 * -kN  sort by a specific field N; e.g., 'sort -k2 -n' sorts lines numerically by the 2nd field
 * -h   display help message
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000             /* max # lines to be sorted */
#define MAXLEN 1000               /* max length of any input line */
#define ALLOCSIZE 10000           /* size of available space */
char *lineptr[MAXLINES];          /* pointers to text lines */
static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

int my_getline(char *, int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);
void my_qsort(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));
int numcmp(char *, char *);
int genstrcmp(char *s1, char *s2);
char *skip_to_field(char *s, int field);
char *alloc(int);

int fold = 0;       /* 1 if fold case */
int directory = 0;  /* 1 if directory order */
int field = 0;      /* 0 means whole line, >0 means sort by that field */

int main(int argc, char *argv[])
{
    int c;
    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */
    int reverse = 0;  /* 1 if reverse sort */

    while (--argc > 0 && **++argv == '-')
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                case 'd':
                    directory = 1;
                    break;
                case 'k':
                    field = atoi(argv[0] + 1);  /* e.g. "-k2" sets field=2 */
                    goto end_of_option;         /* break out of switch so default case isn't reached */
                case 'h':
                     printf(
                        "Usage: sort [-nrfdh] [-kN]\n"
                        "-n   numeric sort\n"
                        "-r   reverse sort order\n"
                        "-f   fold upper and lower case together (ignore case)\n"
                        "-d   directory order (compare only letters, numbers, and blanks)\n"
                        "-kN  sort by a specific field N; e.g., 'sort -k2 -n' sorts lines numerically by the 2nd field\n"
                        "-h   display this help message\n"
                    );
                    exit(0);
                default:
                    printf("sort: illegal option %c\n", c);
                    printf("Usage: sort [-nrfdh] [-kN]\n");
                    break;
            }
        }
end_of_option:  /* stop scanning after -kN to avoid "illegal option N" */
    ;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        if (numeric)
        {
            my_qsort((void **) lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))numcmp);
        }
        else
        {
            my_qsort((void **) lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))genstrcmp);
        }
        writelines(lineptr, nlines, reverse);
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
void writelines(char *lineptr[], int nlines, int reverse)
{
    if (reverse)
    {
        for (int i = nlines - 1; i >= 0; i--)
        {
            printf("%s\n", lineptr[i]);
        }
    }
    else
    {
        while (nlines-- > 0)
        {
            printf("%s\n", *lineptr++);
        }
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
    s1 = skip_to_field(s1, field);
    s2 = skip_to_field(s2, field);

    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* genstrcmp: compare s1 and s2 optionally ignoring non-alphanum characters and/or case */
int genstrcmp(char *s1, char *s2)
{
    s1 = skip_to_field(s1, field);
    s2 = skip_to_field(s2, field);

    int c1, c2;

    for (;; s1++, s2++)
    {
        /* directory order if flag -d specified */
        if (directory)
        {
            while (*s1 && !isalnum(*s1) && *s1 != ' ')
            {
                s1++;
            }
            while (*s2 && !isalnum(*s2) && *s2 != ' ')
            {
                s2++;
            }
        }
        c1 = *s1;
        c2 = *s2;
        /* fold case if flag -f specified */
        if (fold)
        {
            if (c1) c1 = tolower(c1);
            if (c2) c2 = tolower(c2);
        }
        if (c1 != c2)
        {
            return c1 - c2;
        }
        if (c1 == '\0')
        {
            return 0;
        }
    }
}

/* skip_to_field: point to start of specified field */
char *skip_to_field(char *s, int field)
{
    while (field-- > 1 && *s) {
        /* skip current field */
        while (*s && !isspace(*s))
            s++;
        /* skip spaces */
        while (*s && isspace(*s))
            s++;
    }
    return s;
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
