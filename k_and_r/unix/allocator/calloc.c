/* Exercise 8-6 */

#include "malloc.h"

/* calloc: allocate n objects of size size */
void *calloc(size_t n, size_t size)
{
    unsigned i, nb;
    char *p, *q;

    nb = n * size;
    if ((p = q = malloc(nb)) != NULL)
    {
        for (i = 0; i < nb; i++)
        {
            *p++ = 0;
        }
    }
    return q;
}
