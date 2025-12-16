/*
 * Sample 1.5.2
 * count characters version 2
 */

#include <stdio.h>

/* count characters with a for loop (empty body) */

int main(void)
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
