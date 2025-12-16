/*
 * Sample 5.10
 * echo: command-line arguments; 2nd version
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    while (--argc > 0)
    {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
