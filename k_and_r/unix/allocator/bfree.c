/* Exercise 8-8 */

#include "malloc.h"

/* bfree: free an arbitrary block p of n chars */
size_t bfree(char *p, size_t n)
{
    Header *hp;

    if (n < sizeof(Header))
    {
        return 0;  /* too small to be useful */
    }
    hp = (Header *) p;
    hp->s.size = n / sizeof(Header);
    free((void *)(hp + 1));
    return hp->s.size;
}
