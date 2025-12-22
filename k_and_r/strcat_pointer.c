/*
 * Exercise 5-3
 * strcat: concatenate t to end of s; pointer version
 */

#include <stdio.h>

#define BUFFER 100

void my_strcat(char *s, char *t);

int main(void)
{
    char s[BUFFER * 2] = "This is string 's'.";
    char t[BUFFER] = " This is string 't'.";

    my_strcat(s, t);
    printf("s: %s\n", s);

    return 0;
}

void my_strcat(char *s, char *t)
{
    int i, j;

    i = j = 0;
    while (*s != '\0')  /* find end of s */
    {
        s++;  /* move pointer */
    }
    while ((*s++ = *t++) != '\0')  /* copy t to end of s */
        ;
}
