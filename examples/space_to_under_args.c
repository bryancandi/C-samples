/* space_to_under_args.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

void replace_space(char in[], char out[]);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n%s [some string of text]\n", argv[0]);
        return 1;
    }

    size_t total_length = 0;
    for (int i = 1; i < argc; i++)
    {
        total_length += strlen(argv[i]);
        if (i < argc - 1)
        {
            total_length += 1;  /* for space if more args */
        }
    }
    total_length += 1;  /* for null terminator */

    /* alloc memory for the combined string */
    char *combined_string = malloc(total_length);
    if (combined_string == NULL)
    {
        perror("malloc failed at combined_string");
        exit(1);
    }

    combined_string[0] = '\0';

    for (int i = 1; i < argc; i++)
    {
        strcat(combined_string, argv[i]);
        if (i < argc - 1)
        {
            strcat(combined_string, " ");
        }
    }

    /* alloc memory for output string */
    char *modified_string = malloc(total_length);
    if (modified_string == NULL)
    {
        perror("malloc failed at modified_string");
        exit(1);
    }

    replace_space(combined_string, modified_string);

    printf("%s\n", modified_string);

    free(combined_string);
    free(modified_string);

    return 0;
}

void replace_space(char in[], char out[])
{
    for (int i = 0; in[i] != '\0'; ++i)
    {
        if (in[i] == ' ')
        {
            out[i] = '_';
        }
        else
        {
            out[i] = in[i];
        }
    }
}
