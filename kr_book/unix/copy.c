/* 
 * Sample 8.2
 * Low Level I/O - Read and Write
 */

#include <stdio.h>
#include <unistd.h>

#define STDIN  0
#define STDOUT 1

int main(void)
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(STDIN, buf, BUFSIZ)) > 0)
    {
        write(STDOUT, buf, n);
    }
    return 0;
}
