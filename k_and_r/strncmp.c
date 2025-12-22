/*
 * Exercise 5-5
 * strncmp: compare n chars from t to the end of s
 */

#include <stdio.h>

#define CHARS 10  /* number of characters to compare */

int my_strncmp(char *s, char *t, int n);

int main(void)
{
    int n = CHARS;
    char *s = "This is a string.";
    char *t = "This is also a string.";

    if (my_strncmp(s, t, n) == 0)
    {
        printf("Strings match up to position %d\n", n);
    }
    else
    {
        printf("String mismatch before position %d\n", n);
    }

    return 0;
}

int my_strncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0' || --n <= 0)
        {
            return 0;
        }
    }
    return *s - *t;  /* non-zero signifies mismatch */
}
