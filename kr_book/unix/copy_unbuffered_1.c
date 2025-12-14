/* 
 * Sample 8.2
 * Low Level I/O - unbuffered single character copy (1 byte)
 */

#include <stdio.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1

#undef getchar // undef stdio getchar macro

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        write(STDOUT, &c, 1);
    }
    return 0;
}

int getchar(void)
{
    char c;
    
    return (read(STDIN, &c, 1) == 1) ? (unsigned char) c : EOF;
}
