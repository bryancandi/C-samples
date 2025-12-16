/*
 * Sample 3.5
 * reverse: reverse string s in place
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void reverse(char s[]);

int main(void)
{
    int c;
    int i = 0;
    char s[BUFFER];

    while ((c = getchar()) != EOF && c != '\n' && i < BUFFER - 1)
    {
        s[i++] = c;
    }
    s[i] = '\0';

    reverse(s);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
