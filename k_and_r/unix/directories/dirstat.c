/*
 * Exercise 8-5
 * Listing Directories
 * Print inode info
 * Standard POSIX-compliant version
 */

#define _POSIX_C_SOURCE 200809L

#include <dirent.h>     /* standard POSIX dirent.h */
#include <inttypes.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void fsize(char *);

int main(int argc, char **argv)
{
    if (argc == 1)  /* default: current directory */
    {
        fsize(".");
    }
    else
    {
        while (--argc > 0)
        {
            fsize(*++argv);
        }
    }
    return 0;
}

void dirwalk(char *, void(*fcn)(char *));

/* fsize: print size of file "name" */
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1)
    {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if (S_ISDIR(stbuf.st_mode))
    {
        dirwalk(name, fsize);
    }

    struct passwd *pw = getpwuid(stbuf.st_uid);

    printf("%ju ", (uintmax_t)stbuf.st_dev);  /* device identifier */
    printf("%5lu ", stbuf.st_ino);            /* inode number */
    printf("%6o ", stbuf.st_mode);            /* file mode in octal */
    printf("%3lu ", stbuf.st_nlink);          /* number of links */
    printf("%8ld ", stbuf.st_size);           /* file size */
    printf("%-8s ", pw ? pw->pw_name : "?");  /* owner */
    printf("%s\n", name);                     /* file name */
}

/* dirwalk: recursively apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[PATH_MAX];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL)
    {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL)
    {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
        {
            continue;  /* skip self and parent */
        }
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
        {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        }
        else
        {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);  /* recursively call fsize */
        }                  /* could also be called by: fcn(name) */
    }
    closedir(dfd);
}
