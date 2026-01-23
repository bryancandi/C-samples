/*
 * cp: copy source file to destination file
 * Low-level version for Unix systems.
 *
 * Author: Bryan C.
 * Date: 2026-01-23
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define PERMS 0666  /* RW for owner, group, others */

int main(int argc, char *argv[])
{
    int f1, f2;
    ssize_t n;
    char buf[BUFSIZ];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [file 1] [file 2]\n", argv[0]);
        return 1;
    }
    if ((f1 = open(argv[1], O_RDONLY)) == -1)
    {
        perror(argv[1]);
        return 1;
    }
    if ((f2 = creat(argv[2], PERMS)) == -1)
    {
        perror(argv[2]);
        return 1;
    }
    while ((n = read(f1, buf, BUFSIZ)) > 0)
    {
        if (write(f2, buf, n) != n)
        {
            perror("write");
            return 1;
        }
    }
    if (n != 0)
    {
        perror("read");
        return 1;
    }

    close(f1);
    close(f2);
    return 0;
}
