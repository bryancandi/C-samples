/*
 * Exercise 3-2 v2
 * convert escape sequences into real characters
 */

#include <stdio.h>

#define BUFFER 1000

void unescape(char s[], char t[]);;

int main(void)
{
    int i = 0;
    int c = 0;
    char t[BUFFER];
    char s[BUFFER];

    while ((c = getchar()) != EOF && i < BUFFER - 1)
    {
        t[i++] = c;
    }
    t[i] = '\0';

    unescape(s, t);

    printf("%s", s);
    return 0;
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        if (t[i] == '\\')  /* possible beginning of escape sequence */
        {
            switch (t[i + 1])
            {
                case 'n':
                    s[j++] = '\n';
                    i++;  /* skip 'n' in output */
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                case '\\':
                    s[j++] = '\\';
                    i++;
                    break;
                default:  /* not an escape sequence */
                    s[j++] = '\\';
                    break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
