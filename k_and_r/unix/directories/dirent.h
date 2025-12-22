/*
 * dirent.h
 * K&R version of dirent.h
 * For use with obsolete version: dirstat_old.c
 */

#ifndef DIRENT_H
#define DIRENT_H

#define DIRSIZ  14

#define NAME_MAX  14  /* longest filename component */
                      /* system dependent */

typedef struct
{
    long ino;               /* inode number */
    char name[NAME_MAX+1];  /* name + '\0' */
} Dirent;

typedef struct
{
    int fd;    /* file descriptor for directory */
    Dirent d;  /* directory entry */
} KR_DIR;

KR_DIR *kr_opendir(char *dirname);
Dirent *kr_readdir(KR_DIR *dfd);
void kr_closedir(KR_DIR *dfd);

#endif  /* DIRENT_H */
