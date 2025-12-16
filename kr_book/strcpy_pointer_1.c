/*
 * Sample 5.5
 * strcpy: copy t to s; pointer version 1
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
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}
