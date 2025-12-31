/*
 * pwd -- print working directory
 * Classic inode-walking implementation
 * 
 * Author: Bryan C
 * Date: December 30, 2025
 */

#include <dirent.h>
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
    struct stat dot, dotdot;
    char path[PATH_MAX] = "";
    char component[PATH_MAX];

    while (1)
    {
        stat(".", &dot);
        stat("..", &dotdot);

        /* root reached */
        if (dot.st_ino == dotdot.st_ino &&
            dot.st_dev == dotdot.st_dev) {
            break;
        }

        struct dirent *dp;
        DIR *dfd = opendir("..");

        if (!dfd) {
            perror("pwd: opendir");
            exit(1);
        }

        while ((dp = readdir(dfd)) != NULL) {
            /* skip self and parent entries */
            if (strcmp(dp->d_name, ".") == 0 ||
                strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            struct stat entry;
            char entry_path[PATH_MAX];
            snprintf(entry_path, sizeof(entry_path), "../%s", dp->d_name);

            /* cannot stat entry, skip */
            if (stat(entry_path, &entry) == -1) {
                continue;
            }

            /* check for the directory we came from */
            if (entry.st_ino == dot.st_ino &&
                entry.st_dev == dot.st_dev) {

                /* found current (dot) name */
                strcpy(component, dp->d_name);

                /* prepend "/component" to path */
                char tmp[PATH_MAX];
                snprintf(tmp, sizeof(tmp), "/%s%s", component, path);
                strcpy(path, tmp);
                break;
            }
        }

        closedir(dfd);
        chdir("..");  /* move up one level */
    }

    /* print "/" if no path (root) */
    printf("%s\n", path[0] ? path : "/");
    return 0;
}
