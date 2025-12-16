/*
 * Exercise 4-13
 * reverse: reverse string s in place using recursion
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void reverse(char s[], int i, int len);

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

    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);

    return 0;
}

/*
 * reverse: recursively reverse s in place
 * i and len mark the current left and right positions and move inward
 */
void reverse(char s[], int i, int len)
{
    if (i < len)
    {
        char c = s[i];
        s[i] = s[len];
        s[len] = c;
        reverse(s, ++i, --len);
    }
}
