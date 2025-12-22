/*
 * getline.c
 * Custom getline function 
 * Renamed to my_getline() to avoid conflict with POSIX getline()
 */

#include <stdio.h>

#define BUFFER 1000

int my_getline(char s[], int lim);

int main(void)
{
    char line[BUFFER];

    printf("Enter text:\n");
    while (my_getline(line, BUFFER) > 0)
    {
        printf("%s", line);
    }

    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
