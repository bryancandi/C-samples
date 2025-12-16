/*
 * Exercise 3-3
 * expand shorthand - a-z expands to abc...xyz, 0-9 expands to 0123456789
 * a-z0-9 expands to abc...xyz0...9
 * leading and trailing '-' are taken literally and printed
 */

#include <stdio.h>

#define BUFFER 1000

void expand(char s1[], char s2[]);

int main(void)
{
    int c;
    int i = 0;
    char s[BUFFER];
    char e[BUFFER];

    while ((c = getchar()) != EOF && c != '\n' && i < BUFFER - 1)
    {
        s[i++] = c;
    }
    s[i] = '\0';

    expand(s, e);
    printf("%s\n", e);

    return 0;
}

void expand(char s1[], char s2[])
{
    char c;
    int i, j;
    i = j = 0;

    while ((c = s1[i++]) != '\0')  /* get char from s1 as char c */
    {
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            i++;
            while (c < s1[i])  /* expand shorthand */
            {
                s2[j++] = c++;
            }
        }
        else
        {
            s2[j++] = c;  /* otherwise copy characters into s2 */
        }
    }
    s2[j] = '\0';
}
