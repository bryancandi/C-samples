/* 
 * Sample 8.2
 * Low Level I/O - unbuffered single character copy (1 byte) v2
 */

#include <unistd.h>

#define STDIN  0
#define STDOUT 1

int main(void)
{
    char c;

    while (read(STDIN, &c, 1) == 1)
    {
        write(STDOUT, &c, 1);
    }
    return 0;
}
