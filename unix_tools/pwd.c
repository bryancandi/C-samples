/*
 * pwd -- print working directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    struct stat dot, dotdot;
    char path[4096] = "";
    char component[256];

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
            fprintf(stderr, "pwd: opendir error\n");
            exit(1);
        }

        while ((dp = readdir(dfd)) != NULL) {
            if (strcmp(dp->d_name, ".") == 0 ||
                strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            struct stat entry;
            char entry_path[512];
            snprintf(entry_path, sizeof(entry_path), "../%s", dp->d_name);

            if (stat(entry_path, &entry) == -1) {  /* error */
                continue;
            }

            /* check for the directory we came from */
            if (entry.st_ino == dot.st_ino &&
                entry.st_dev == dot.st_dev) {

                /* found current (dot) name */
                strcpy(component, dp->d_name);

                /* prepend "/component" to path */
                char tmp[4096];
                snprintf(tmp, sizeof(tmp), "/%s%s", component, path);
                strcpy(path, tmp);
                break;
            }
        }

        closedir(dfd);
        chdir("..");  /* move up one level */
    }

    printf("%s\n", path[0] ? path : "/");
    return 0;
}
