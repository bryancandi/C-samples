/*
 * grep.c
 * to-do: handle files as args
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void patterncmp(char *, FILE *, char *prog);

int main(int argc, char *argv[])
{
    char *prog = argv[0];
    char buf[BUFSIZ];

    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s PATTERN [FILE]...\n", prog);
        exit(1);
    }
    if (argc == 2)
    {
        patterncmp(argv[1], stdin, prog);
    }

    /* to-do: handle files as args */

    return 0;
}

void patterncmp(char *pattern, FILE *ifp, char *prog)
{
    int c;
    int n = 0;
    char buf[BUFSIZ];

    while ((c = getc(ifp)) != EOF && n < BUFSIZ - 1)
    {
        buf[n++] = c;

        if (c == '\n')
        {
            buf[n] = '\0';
            char *p;
            char *pos = buf;  /* updateable pointer to position in buf */
            int found = 0;    /* line contains at least one match if */

            while ((p = strstr(pos, pattern)) != NULL)
            {
                int p_start = (p - pos);  /* integer position of pattern (p) in the buffer */
                int p_end = p_start + strlen(pattern);  /* integer position after pattern in the buffer */
                for (int i = 0; i < p_start; i++)
                {
                    putchar(pos[i]);
                }
                printf("\033[0;31m");
                printf("%s", pattern);
                printf("\033[0m");
                pos = p + strlen(pattern);
                found = 1;
            }
            if (found)
            {
                printf("%s", pos);
            }
            n = 0;
        }
    }
}
