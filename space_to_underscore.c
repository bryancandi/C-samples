/* space_to_underscore.c */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int main(void)
{
    char line[MAXLINE];

    if (fgets(line, MAXLINE, stdin) == NULL)
    {
        return 1;
    }
    else
    {
        line[strcspn(line, "\n")] = 0;  /* replace '\n' with '\0' */
    }

    for (int i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == ' ')
        {
            line[i] = '_';
        }
    }

    printf("%s\n", line);

    return 0;
}
