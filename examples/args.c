/*
 * args.c
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Args:\n");
    for (int i = 1; --argc > 0; i++)
    {
        printf("%d: %s\n", i, *++argv);
    }
    return 0;
}
