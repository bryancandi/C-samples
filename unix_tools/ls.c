/*
 * ls: list directory contents
 *
 * TODO: add flags (-a, -l, -r) for additional output styles
 *
 * Author: Bryan C.
 * Date: 2026-01-24
 */

#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printdir(struct dirent **namelist, int n);
void freedir(struct dirent **namelist, int n);

int main(int argc, char *argv[])
{
    struct dirent **namelist;
    int n;

    if (argc == 1)
    {
        n = scandir(".", &namelist, NULL, alphasort);
        if (n == -1)
        {
            perror("scandir");
            return 1;
        }
        printdir(namelist, n);
        freedir(namelist, n);
        free(namelist);
    }
    else
    {
        while (--argc > 0)
        {
            n = scandir(*++argv, &namelist, NULL, alphasort);
            if (n == -1)
            {
                perror("scandir");
                return 1;
            }
            printf("%s:\n", *argv);
            printdir(namelist, n);
            freedir(namelist, n);
            free(namelist);
            if (argc > 1)
            {
                printf("\n");
            }
        }
    }  
    return 0;
}

/* Print directory entry names from namelist, excluding "." and "..". */
void printdir(struct dirent **namelist, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(namelist[i]->d_name, ".") != 0 && strcmp(namelist[i]->d_name, "..") != 0)
        {
            printf("%s\n", namelist[i]->d_name);
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
