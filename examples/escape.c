/*
 * Get string from stdin.
 * Print some escape sequences in the string.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[BUFSIZ];
    if (fgets(buf, sizeof(buf), stdin) == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(buf) + 1; i < n; i++)
    {
        if(buf[i] == '\n')
        {
            printf("\\n");
        }
        else if (buf[i] == '\t')
        {
            printf("\\t");
        }
        else if (buf[i] == '\0')
        {
            printf("\\0");
        }
        else
        {
            putchar(buf[i]);
        }
    }
    putchar('\n');
    return 0;
}
