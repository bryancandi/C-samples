/*
 * cat.c
 * Concatenate file(s) to standard output
 * Author: Bryan C.
 * Date: December 23, 2025
 */

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *, FILE *, char *);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];  /* program name for stderr */

    if (argc == 1)  /* no args; copy stdin to stdout */
    {
        filecopy(stdin, stdout, prog);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);  /* exit(1): read error */
            }
            else
            {
                filecopy(fp, stdout, prog);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);  /* exit(2): write error */
    }
    return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp, char *prog)
{
    int c;

    while ((c = fgetc(ifp)) != EOF)
    {
        if (putc(c, ofp) == EOF)
        {
            fprintf(stderr, "%s: write error\n", prog);
            exit(2);
        }
    }
}
