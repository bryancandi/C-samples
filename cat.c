/*
 * cat.c
 * Concatenate file to standard output
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");  /* open file in read mode */
    if (file == NULL)
    {
        printf("%s: Cannot access file '%s'\n", argv[0], argv[1]);
        return 2;
    }

    char c;

    /* Read 'file' one character at a time with fgetc() and print that character until EOF */
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }

    fclose(file);

    return 0;
}
