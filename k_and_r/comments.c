/*
 * Exercise 1-23
 * Remove all comments from C source file
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
    {
        printf("Usage: %s SOURCE DEST\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "r");  /* open source file to read */
    if (src == NULL)
    {
        printf("%s: Source file '%s' does not exist\n", argv[0], argv[1]);
        return 2;
    }

    FILE *dst = fopen(argv[2], "w");  /* open destination file to write */
    if (dst == NULL)
    {
        printf("%s: Cannot create destination file '%s'\n", argv[0], argv[2]);
        return 3;
    }

    int c, next, nnext;

    while ((c = fgetc(src)) != EOF)
    {
        if (c == '/')
        {
            next = fgetc(src);
            if (next == '*')
            {
                /* inside block comment */
                while ((c = fgetc(src)) != EOF)
                {
                    if (c == '\n')
                    {
                        fputc('\n', dst);  /* preserve line structure */
                    }
                    else if (c == '*')
                    {
                        nnext = fgetc(src);
                        if (nnext == '/')
                        {
                            break;
                        }
                        else
                        {
                            /* go back one char if no '/' */
                            ungetc(nnext, src);
                        }
                    }
                }
            }
            else if (next == '/')
            {
                /* inside line comment */
                while ((c = fgetc(src)) != EOF && c != '\n')
                    ;
                if (c == '\n')
                {
                    fputc('\n', dst);
                }
            }
            else
            {
                /* Not a comment — output both */
                fputc('/', dst);
                fputc(next, dst);
            }
        }
        else
        {
            fputc(c, dst);
        }
    }

    fclose(src);
    fclose(dst);

    return 0;
}
