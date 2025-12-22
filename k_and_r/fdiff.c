/*
 * Exercise 7-6
 * fdiff: compare two files and print the first line where they differ
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c1, c2;
    int linenum = 1;
    int mismatch = 0;
    FILE *fp1, *fp2;
    char *prog = argv[0];  /* program name for error output */

    if (argc != 3)
    {
        fprintf(stderr, "%s: must provide two files to compare\n", prog);
        exit(1);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
        exit(2);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "%s: can't open %s\n", prog, argv[2]);
        exit(3);      
    }

    while (1)
    {
        c1 = getc(fp1);
        c2 = getc(fp2);

        if (c1 == EOF && c2 == EOF)
        {
            break;  /* files match */
        }
        if (c1 != c2)
        {
            fprintf(stderr, "%s: file mismatch at line %d\n", prog, linenum);
            mismatch = 1;
            break;
        }
        if (c1 == '\n')
        {
            linenum++;
        }
    }

    if (!mismatch)
    {
        printf("%s: files match\n", prog);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
