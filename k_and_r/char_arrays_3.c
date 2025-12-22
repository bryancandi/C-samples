/* Exercise 1-17 */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char[], int maxline);

/* print all lines that are longer than 80 chars */
int main(void)
{
    int len;  /* current line length */
    int max;  /* maximum length seen so far */
    char line[MAXLINE];  /* current input line */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
        }
        if (max > 80)  /* there was a line longer than 80 chars */
        {
            printf("%s", line);
            max = 0;  /* reset max for next loop */
        }
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
