/* Exercise 1-24 */

/*
 * TO-DO:
 * work on check functions
 */

#include <stdint.h>
#include <stdio.h>

#define MAX_ERRORS 1000

typedef uint8_t BYTE;

void delim_check(FILE *file);
void remove_comments(FILE *src_file, FILE *tmp_file);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *src_file = fopen(argv[1], "r");
    if (!src_file)
    {
        printf("Source file '%s' does not exist\n", argv[1]);
        return 2;
    }

    FILE *tmp_file = fopen("tmp_file.c", "w+");
    if (!tmp_file)
    {
        printf("Cannot create temporary file\n");
        fclose(src_file);
        return 3;
    }

    remove_comments(src_file, tmp_file);

    /* reposition file pointer to start of file for reading (it is currently at EOF after writing) */
    rewind(tmp_file);

    delim_check(tmp_file);
    
    fclose(src_file);
    fclose(tmp_file);

    /* delete file when fininshed */
    remove("tmp_file.c");

    return 0;
}

void remove_comments(FILE *src_file, FILE *tmp_file)
{
    int c, next, nnext;

    while ((c = fgetc(src_file)) != EOF)
    {
        if (c == '/')
        {
            next = fgetc(src_file);
            if (next == '*')
            {
                /* inside block comment */
                while ((c = fgetc(src_file)) != EOF)
                {
                    if (c == '\n')
                    {
                        fputc('\n', tmp_file);  /* preserve line structure */
                    }
                    else if (c == '*')
                    {
                        nnext = fgetc(src_file);
                        if (nnext == '/')
                        {
                            break;
                        }
                        else
                        {
                            /* go back one char if no '/' */
                            ungetc(nnext, src_file);
                        }
                    }
                }
            }
            else if (next == '/')
            {
                /* inside line comment */
                while ((c = fgetc(src_file)) != EOF && c != '\n')
                    ;
                if (c == '\n')
                {
                    fputc('\n', tmp_file);
                }
            }
            else
            {
                /* Not a comment — output both */
                fputc('/', tmp_file);
                fputc(next, tmp_file);
            }
        }
        else
        {
            fputc(c, tmp_file);
        }
    }
}

void delim_check(FILE *file)
{
    char c;
    int line_counter = 1;
    int open_parens[MAX_ERRORS];
    int open_count = 0;
    int extra_parens[MAX_ERRORS];
    int extra_count = 0;

    /* read the file one char at a time and check for balance */
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '(')
        {
            if (open_count < MAX_ERRORS)
            {
                /* add entry for opening paren at position 'open++' */
                open_parens[open_count++] = line_counter;
            }
            else
            {
                fprintf(stderr, "Overflow: too many open parentheses (line %d)\n", line_counter);
            }
        }
        else if (c == ')')
        {
            if (open_count > 0)
            {
                /* matched one opening paren; pop it */
                --open_count;
            }
            else
            {
                if (extra_count < MAX_ERRORS)
                {
                    extra_parens[extra_count++] = line_counter;
                }
                else
                {
                    fprintf(stderr, "Overflow: too many unmatched parentheses (line %d)\n", line_counter);
                }
            }
        }

        if (c == '\n')
        {
            ++line_counter;
        }
    }

    if (open_count == 0 && extra_count == 0)
    {
        printf("Parentheses '()' are balanced.\n");
        return;
    }

    if (extra_count > 0)
    {
        printf("Unmatched closing ')' found at line%s: ", extra_count > 1 ? "s" : "");
        for (int i = 0; i < extra_count; ++i)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%i", extra_parens[i]);
        }
        printf(".\n");
    }

    if (open_count > 0)
    {
        printf("Unclosed '(' opened at line%s: ", open_count > 1 ? "s" : "");
        for (int i = 0; i < open_count; ++i)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%i", open_parens[i]);
        }
        printf(".\n");
    }
    
    /*
     *TO-DO: add other delimiter balance checks [] {} etc.
     * Check for chars between "" or '' and ignore
     * Change delim_function to int, return values to main
     * Move printf statements out of delim_function to main; print based on return value
     */
}
