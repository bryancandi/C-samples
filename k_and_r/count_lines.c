/*
 * Sample 1.5.3
 * Count lines
 */

#include <stdio.h>

int main(void)
{
    int c, nl;
    
    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}
