/*
 * Exercise 5-12
 * tail: print the last n lines of input (default 10)
 * Usage: tail [-n] < inputfile
 * Lines are stored in a fixed-size buffer with wrap-around.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10  /* default number of lines to print */
#define LINES 100    /* max number of lines to print */
#define MAXLEN 100   /* max length of an input line */

void error(char *);
int my_getline(char *, int);

/* tail: print last n lines of input */
int main(int argc, char *argv[])
{
    char *p;
    char *buf;             /* pointer to large buffer */
    char *bufend;          /* end of the buffer */
    char line[MAXLEN];     /* current input line */
    char *lineptr[LINES];  /* pointers to lines read */
    int first, i, last, len, n, nlines;

    if (argc == 1)  /* no arguments present */
    {
        n = DEFLINES;  /* use default number of lines */
    }
    else if (argc == 2 && **++argv == '-')
    {
        n = atoi(argv[0] + 1);
    }
    else
    {
        error("usage: tail [-n]");
    }
    if (n < 1 || n > LINES)  /* unreasonable value for n? */
    {
        n = LINES;
    }
    for (i = 0; i < LINES; i++)
    {
        lineptr[i] = NULL;
    }
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
    {
        error("tail: cannot allocate buf");
    }
    bufend = buf + LINES * MAXLEN;
    last = 0;  /* index of last line read */
    nlines = 0;  /* number of lines read */
    while ((len = my_getline(line, MAXLEN)) > 0)
    {
        if (p + len + 1 >= bufend)
        {
            p = buf;  /* buffer wrap around */
        }
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES)
        {
            last = 0;  /* ptrs to buffer wrap around */
        }
        p += len + 1;
        nlines++;
    }
    if (n > nlines)  /* req. lines more than rec.? */
    {
        n = nlines;
    }
    first = last - n;
    if (first < 0)  /* it did wrap around the list */
    {
        first += LINES;
    }
    for (i = first; n-- > 0; i = (i + 1) % LINES)
    {
        printf("%s", lineptr[i]);
    }
    return 0;
}

/* my_getline: read a line from standard input into line, up to max-1 characters */
int my_getline(char *line, int max)
{
    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

/* error: print error message and exit */
void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}
