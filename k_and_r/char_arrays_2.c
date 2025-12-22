/* Exercise 1-16 */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char[], int maxline);
void copy(char to[], char from[]);

/* print longest input line up to 'MAXLINE'; print length beyond max */
int main(void)
{
    int total = 0;   /* variable to store line length beyond the 'MAXLINE' value */
    int buffer = 0;  /* temporarily store 'len' values until a newline is reached */
    int len;         /* current line length */
    int max;         /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        buffer += len;
        if (line[len - 1] == '\n')
        {
            if (buffer > total)
            {
                total = buffer;
            }
            buffer = 0;
        }
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)  /* there was a line */
    {
        printf("Length: %i\n", total);
        printf("Line: %s", longest);
    }
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from [i]) != '\0')
    {
    ++i;
    }
}
