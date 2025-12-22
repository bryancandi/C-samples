/* Exercise 1-20 */

#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000

int my_getline(char[], int maxline);
void detab(char[], char[]);

int main(void)
{
    int len;
    char line[MAXLINE];
    char dt_line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        detab(line, dt_line);

        printf("%s", dt_line);
    }
}

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

void detab(char in[], char out[])
{
    int i = 0;    /* input index */
    int j = 0;    /* output index */
    int col = 0;  /* current column position */

    while (in[i] != '\0')
    {
        if (in[i] == '\t')
        {
            printf("[TAB detected at col %d]\n", col);
            int spaces = TABSTOP - (col % TABSTOP);
            for (int k = 0; k < spaces; k++)
            {
                out[j++] = ' ';
                col++;
            }
        }
        else
        {
            out[j++] = in[i];
            if (in[i] == '\n')
                col = 0;  /* reset column count at newline */
            else
                col++;
        }
        i++;
    }
    out[j] = '\0';
}
