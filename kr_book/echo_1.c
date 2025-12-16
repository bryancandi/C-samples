/*
 * Sample 5.10
 * echo: command-line arguments; 1st version
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
