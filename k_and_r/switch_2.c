/*
 * Exercise 3-2 
 * convert tabs and newline characters into visible escape sequences
 */

#include <stdio.h>

#define BUFFER 1000

void escape(char s[], char t[]);;

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

    escape(s, t);

    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != 0; i++)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
