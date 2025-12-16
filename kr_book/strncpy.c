/*
 * Exercise 5-5
 * strncpy: copy n characters from t to s
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS 4  /* characters to copy */

void my_strncpy(char *s, char *t, int n);

int main(void)
{
    int n = CHARS;
    char *t = "This is a string.";
    char *s = malloc(strlen(t) + 1);
    if (s == NULL)
    {
        printf("error: malloc failed\n");
        return 1;
    }

    my_strncpy(s, t, n);
    printf("s: %s\n", s);

    free(s);
    return 0;
}

void my_strncpy(char *s, char *t, int n)
{
    while (*t && n-- > 0)
    {
        *s++ = *t++;
    }
    while (n-- > 0)
    {
        *s++ = '\0';
    }
    *s = '\0';
}
