/*
 * main.c
 * Test allocator functions
 * To-do: add tests for functions calloc and bfree
 */

#include "malloc.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *t = "This is a string.";
    char *s = malloc(strlen(t) + 1);
    if (s == NULL)
    {
        printf("error: malloc failed\n");
        return 1;
    }

    strcpy(s, t);
    printf("t: %s\n", t);
    printf("s: %s\n", s);

    free(s);
    return 0;
}
