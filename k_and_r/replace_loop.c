/*
 * Exercise 2-2
 * Replace for loop with equivalent
 */

#include <stdio.h>
#define MAXLINE 10

int my_getline(char[], int maxline);

/* print input line */
int main(void)
{
    int len;  /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c;
    int i = 0;

    while (i < lim - 1)
    {
        c = getchar();

        if (c == EOF)
        {
            break;  /* stop on EOF */
        }

        if (c == '\n')
        {
            break;  /* stop on newline */
        }

        s[i] = c;
        ++i;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
