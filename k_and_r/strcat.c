/*
 * Sample 2.8
 * strcat: concatenate t to end of s; s must be big enough
 */

#include <stdio.h>

#define BUFFER 100

void my_strcat(char s[], char t[]);

int main(void)
{
    char s[BUFFER * 2] = "This is string 's'.";
    char t[BUFFER] = " This is string 't'.";

    my_strcat(s, t);
    printf("s: %s\n", s);

    return 0;
}

void my_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')  /* find end of s */
    {
        i++;
    }
    while ((s[i++] = t[j++]) != '\0')  /* copy t to end of s */
        ;
}
