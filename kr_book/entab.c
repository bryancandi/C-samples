/* Exercise 1-21 */

#include <stdio.h>

#define TABSTOP 4
#define MAXLINE 1000

int my_getline(char[], int maxline);
void entab(char[], char[]);

int main(void)
{
    int len;
    char line[MAXLINE];
    char et_line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        entab(line, et_line);

        printf("%s", et_line);
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

void entab(char in[], char out[])
{
    int i = 0;  /* input index */
    int j = 0;  /* output index */
    int counter = 0;

    while (in[i] != '\0')
    {
        if (in[i] == ' ')
        {
            ++counter;
            if (counter == TABSTOP)
            {
                printf("[4 spaces detected; tab inserted]\n");
                out[j++] = '\t';
                counter = 0;
            }
        }
        else
        {
            while (counter > 0)
            {
                out[j++] = ' ';
                --counter;
            }
            out[j++] = in[i];
        }
        ++i;
    }
    out[j] = '\0';
}
