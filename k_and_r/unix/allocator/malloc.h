/*
 * malloc.h
 * Header file for K&R storage allocator functions
 */

#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>

void *malloc(size_t nbytes);
void free(void *ap);
void *calloc(size_t n, size_t size);
size_t bfree(char *p, size_t n);

typedef long Align; /* for alignment to long boundary */

union header {      /* block header */
    struct
    {
        union header *ptr;  /* next block if on free list */
        size_t size;        /* size of this block */
    } s;
    Align x;        /* force alignment of blocks */
};

typedef union header Header;

#endif  /* MALLOC_H */
