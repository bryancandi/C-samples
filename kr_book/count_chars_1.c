/*
 * Sample 1.5.2
 * count characters version 1
 */

#include <stdio.h>

/* count characters with a while loop */

int main(void)
{
    long nc;
    
    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}
