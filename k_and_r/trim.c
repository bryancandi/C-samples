/* Sample 3.7 */

#include <stdio.h>
#include <string.h>

#define BUFFER 1000

int trim(char s[]);

int main(void)
{
    int c;
    int i = 0;
    char s[BUFFER];

    while ((c = getchar()) != EOF && i < BUFFER - 1 && c != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';

    printf("s: \"%s\"\n", s);
    trim(s);
    printf("t: \"%s\"\n", s);

    return 0;
}

int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n + 1] = '\0';
    return n;
}
