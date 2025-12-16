/*
 * Sample 5.5
 * strcpy: copy t to s; array subscript version 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcpy(char *s, char *t);

int main(void)
{
    char *t = "This is a string.";
    char *s = malloc(strlen(t) + 1);
    if (s == NULL)
    {
        printf("error: malloc failed\n");
        return 1;
    }

    printf("t: %s\n", t);
    my_strcpy(s, t);
    printf("s: %s\n", s);

    free(s);
    return 0;
}

void my_strcpy(char *s, char *t)
{
    int i = 0;

    while ((s[i] = t[i]) != '\0')
    {
        i++;
    }
}
