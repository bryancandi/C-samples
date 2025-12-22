/*
 * Sample 5.10
 * find: print lines that match pattern from 1st arg; 1st version
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
    {
        printf("Usage: find pattern\n");
    }
    else
    {
        while (my_getline(line, MAXLINE) > 0)
        {
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int my_getline(char *line, int max)
{
    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}
