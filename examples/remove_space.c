/* remove_space.c */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int main(void)
{
    char s[BUFFER];
    int j = 0;

    if (fgets(s, BUFFER, stdin) == NULL)
    {
        return 1;
    }
    else
    {
        /*
         * remove trailing newline provided by fgets()
         * use strcspn to find the position of '\n' char and replace it with a null terminator
         */
        s[strcspn(s, "\n")] = 0;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isspace(s[i]))
        {
            t[j] = s[i];
            j++;
        }
    }
    t[j] = '\0';

    printf("Original: %s\n", s);
    printf("No Space: %s\n", t);

    free(t);
}
