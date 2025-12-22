/*
 * Sample 5.5
 * strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
 */

#include <stdio.h>

int my_strcmp(char *s, char *t);

int main(void)
{
    char *s = "This is also a string.";
    char *t = "This is also a string.";

    printf("%d\n", my_strcmp(s, t));

    return 0;
}

int my_strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
        {
            return 0;
        }
    }
    return s[i] - t[i];
}
