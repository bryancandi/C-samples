/* Sample 5.3 */

#include <stdio.h>

#define MAXLINE 1000

int my_strlen(char *s);

int main(void)
{
    int i;
    char c;
    char line[MAXLINE];

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    line[i] = '\0';

    int len = my_strlen(line);
    printf("%i\n", len);

    return 0;
}

/* my_strlen: return length of 's' excluding '\0' */
int my_strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
    {
        n++;
    }

    return n;
}
