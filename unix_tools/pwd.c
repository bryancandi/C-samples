/*
 * pwd: Print working (current) directory
 * Print working directory by walking up the tree and matching directory inodes
 *
 * Author: Bryan C
 * Date: December 30, 2025
 */

#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

int main(void)
{
    struct stat currentd, parentd;
    char path[PATH_MAX] = "";

    while (1) {
        /* stat "." and ".." to identify current directory and its parent */
        if (stat(".", &currentd) == -1 || stat("..", &parentd) == -1) {
            perror("pwd: stat");
            exit(1);
        }

        /* current is parent; root reached */
        if (currentd.st_ino == parentd.st_ino && currentd.st_dev == parentd.st_dev) {
            break;
        }

        struct dirent *dp;
        DIR *dfd = opendir("..");

        if (!dfd) {  /* opendir failed, exit */
            perror("pwd: opendir");
            exit(1);
        }

        while ((dp = readdir(dfd)) != NULL) {
            /* skip self and parent entries */
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            /* form pathname of parent directory entries to identify current directory */
            struct stat entry;
            char entrypath[PATH_MAX];
            snprintf(entrypath, sizeof(entrypath), "../%s", dp->d_name);

            /* cannot stat entry; skip */
            if (stat(entrypath, &entry) == -1) {
                continue;
            }

            /* check for the directory we came from in current directory */
            if (entry.st_ino == currentd.st_ino && entry.st_dev == currentd.st_dev) {
                /* prepend current directory name to path */
                char tmp[PATH_MAX];
                snprintf(tmp, sizeof(tmp), "/%s%s", dp->d_name, path);
                strcpy(path, tmp);
                break;
            }
        }

        closedir(dfd);

        /* move up one level */
        if (chdir("..") == -1) {
            perror("pwd: chdir");
            exit(1);
        }
    }

    /* print path; path is empty: print root */
    printf("%s\n", path[0] ? path : "/");
    return 0;
}
