/* combine.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* calculate buffer size */
    size_t total_length = 0;
    for (int i = 1; i < argc; i++)
    {
        total_length += strlen(argv[i]);
        if (i < argc - 1)  /* add room for a space if not the last arg (-1) */
        {
            total_length += 1;
        }
    }
    total_length += 1;  /* for null terminator */

    /* alloc memory for the combined string */
    char *combined_string = malloc(total_length);
    if (combined_string == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    /* initialize the combined string as a empty string */
    combined_string[0] = '\0';

    /* concatenate args */
    for (int i = 1; i < argc; i++)
    {
        strcat(combined_string, argv[i]);
        if (i < argc - 1)  /* add a space if not the last arg (-1) */
        {
            strcat(combined_string, " ");
        }
    }

    printf("Combined arguments: \"%s\"\n", combined_string);

    free(combined_string);

    return 0;
}
