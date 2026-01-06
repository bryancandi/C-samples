/*
 * fgrep.c
 * A simple fixed-string search program, inspired by Unix `fgrep`
 * Matching substrings are highlighted in red using ANSI escape codes
 * Usage: ./fgrep PATTERN [FILE]...
 * Author: Bryan C
 * Date: December 23, 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void patterncmp(FILE *, char *);

int main(int argc, char *argv[])
{
    FILE *fp;
    int file = 1;
    char *prog = argv[0];

    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s PATTERN [FILE]...\n", prog);
        exit(1);
    }
    if (argc == 2)
    {
        printf("\033[36mstdin:\033[0m\n");
        patterncmp(stdin, argv[1]);
    }
    else
    {
        while (--argc > 1)
        {
            if ((fp = fopen(argv[++file], "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s\n", prog, argv[file]);
                exit(2);
            }
            else
            {
                printf("\033[36mfile: %s\033[0m\n", argv[file]);
                patterncmp(fp, argv[1]);
                fclose(fp);
            }
        }
    }
    return 0;
}

/* patterncmp: compare file ifp with string pattern; print lines containing match w/ pattern in red */
void patterncmp(FILE *ifp, char *pattern)
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
            char *p;          /* pointer for strstr */
            char *pos = buf;  /* scanning pointer for current position in buf */
            int found = 0;    /* default: no match */

            if (pattern[0] == '^')  /* match only if line starts with pattern (skip leading '^') */
            {
                if (strstr(buf, pattern + 1) == buf)  /* move pos past the matched pattern */
                {
                    pos = pos + strlen(pattern + 1);
                    printf("\033[0;31m%s\033[0m%s", pattern + 1, pos);
                }
            }
            if (pattern[strlen(pattern) - 1] == '$')  /* match only if line ends with pattern (skip trailing '$') */
            {
                int blen = strlen(buf);
                int plen = strlen(pattern) - 1;

                if (buf[blen - 1] == '\n')  /* remove trailing newline if present in buf */
                {
                    blen--;
                }

                char *tail = buf + (blen - plen);  /* pointer to start of pattern at end of line */

                if (strncmp(tail, pattern, plen) == 0)
                {
                    printf("%.*s", (int)(tail - buf), buf);
                    printf("\033[0;31m%.*s\033[0m\n", plen, pattern);
                }
            }
            else
            {
                while ((p = strstr(pos, pattern)) != NULL)
                {
                    int p_start = p - pos;  /* integer position of pattern start in pos (buf) */    

                    for (int i = 0; i < p_start; i++)  /* print characters before pattern */
                    {
                        putchar(pos[i]);
                    }
                    printf("\033[0;31m%s\033[0m", pattern); /* print pattern in red then reset color */

                    found = 1;  /* signal a match */
                    pos = p + strlen(pattern);  /* update pos past the last matched pattern */
                }
            }

            if (found)  /* print remainder of line after last match */
            {
                fputs(pos, stdout);
            }

            n = 0;  /* reset buffer for next line */
        }
    }
}
