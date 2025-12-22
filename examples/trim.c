/* trim.c */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

void trim(char *line);

int main(void)
{
    char line[BUFFER];

    printf("Enter a string to trim: ");
    if (fgets(line, BUFFER, stdin) == NULL)
    {
        return 1;
    }
    else
    {
        line[strcspn(line, "\n")] = 0;  /* remove trailing newline from fgets */
    }

    char *line_t = malloc(strlen(line) + 1);
    if (line_t == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    strcpy(line_t, line);

    printf("Entered: \"%s\"\n", line);

    trim(line_t);

    printf("Trimmed: \"%s\"\n", line_t);

    free(line_t);
    
    return 0;
}

void trim(char *line)
{
    int start_index = 0;
    int end_index = strlen(line) - 1;

    if (line == NULL)
    {
        return;
    }

    while (isspace(line[start_index]))
    {
        start_index++;
    }

    while (end_index >= start_index && isspace(line[end_index]))
    {
        end_index--;
    }

    int i = 0;
    while (start_index + i <= end_index) {
        line[i] = line[start_index + i];
        i++;
    }

    line[i] = '\0';
}
