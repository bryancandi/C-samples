/*
 * ls: list directory contents
 * Usage: ls [OPTION]... [DIR]...
 *
 * TODO: add flags (-l, -r) for additional output styles
 *
 * Author: Bryan C.
 * Date: 2026-01-24
 */

#define _DEFAULT_SOURCE

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printdir(struct dirent **namelist, int n, int a);
void freedir(struct dirent **namelist, int n);

int main(int argc, char *argv[])
{
    struct dirent **namelist;
    int n;
    int opt_a = 0;

    /* advance past program name */
    argc--;
    argv++;

    while (argc > 0 && argv[0][0] == '-')
    {
        const char *p = argv[0] + 1;
        while (*p)
        {
            if (*p++ == 'a')
            {
                opt_a = 1;
            }
            else
            {
                fprintf(stderr, "ls: illegal option '%c'\n", *--p);
                return 1;
            }
        }
        argc--;
        argv++;
    }
    if (argc == 0)
    {
        n = scandir(".", &namelist, NULL, alphasort);
        if (n == -1)
        {
            perror("ls");
            return 1;
        }
        printdir(namelist, n, opt_a);
        freedir(namelist, n);
        free(namelist);
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            n = scandir(argv[i], &namelist, NULL, alphasort);
            if (n == -1)
            {
                fprintf(stderr, "ls: cannot access '%s': %s\n", argv[i], strerror(errno));
                return 1;
            }
            if (argc > 1)
            {
                printf("%s:\n", argv[i]);
            }
            printdir(namelist, n, opt_a);
            freedir(namelist, n);
            free(namelist);
            if (i < argc - 1)
            {
                printf("\n");
            }
        }
    }  
    return 0;
}

/* Print directory entry names from namelist; handle optional arguments */
void printdir(struct dirent **namelist, int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (a == 1)
        {
            printf("%s\n", namelist[i]->d_name);
        }
        else
        {
            if (strcmp(namelist[i]->d_name, ".") != 0 && strcmp(namelist[i]->d_name, "..") != 0)
            {
                printf("%s\n", namelist[i]->d_name);
            }
        }
    }
}

/* Free all directory entry structures in namelist (not the array itself). */
void freedir(struct dirent **namelist, int n)
{
    for (int i =0; i < n; i++)
    {
        free(namelist[i]);
    }
}
