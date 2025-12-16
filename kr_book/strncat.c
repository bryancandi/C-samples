/*
 * Exercise 5-5
 * strncat: concatenate n chars from t to the end of s
 */

#include <stdio.h>

#define BUFFER 100
#define CHARS 5

void my_strncat(char *s, char *t, int n);

int main(void)
{
    int n = CHARS;
    char s[BUFFER * 2] = "This is string 's'.";
    char t[BUFFER] = " This is string 't'.";

    my_strncat(s, t, n);
    printf("s: %s\n", s);

    return 0;
}

void my_strncat(char *s, char *t, int n)
{
    int i, j;

    i = j = 0;
    while (*s != '\0')  /* find end of s */
    {
        s++;  /* move pointer */
    }
    while (n-- > 0 && *t != '\0')  /* copy t to end of s until n is 0 */
    {
        *s++ = *t++;
    }
    *s = '\0';
}
