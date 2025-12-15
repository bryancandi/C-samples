/*
 * Exercise 8-1
 * cat: concatenate files using low-level buffered I/O
 */

#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fdcopy(int fd, const char *prog);
void error(char *fmt, ...);

int main(int argc, char *argv[])
{
    int fd;
    char *prog = argv[0]; // for error output

    if (argc == 1) // no file; use standard input
    {
        fdcopy(STDIN_FILENO, prog);
    }
    else if (argc > 1)
    {
        while (--argc > 0)
        {
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
            {
                error("%s: can't open %s", prog, *argv);
            }
            fdcopy(fd, prog);
            close(fd);
        }
    }
    return 0;
}

// fdcopy: copy file descriptor to standard output
void fdcopy(int fd, const char *prog)
{
    int n;
    char buf[BUFSIZ]; // read buffer

    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            error("%s: write error", prog);
        }
    }
    if (n < 0)
    {
        error("%s: read error", prog);
    }    
}

// error: print an error message and die
void error(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
