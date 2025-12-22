# K&R allocator:
# - uses sbrk()
# - free() manages a private free list
# GCC warns because it assumes libc malloc/free semantics.

CC = cc

# Suppress false positive for K&R allocator (sbrk-backed free list)
CFLAGS = -Wall -Wextra -std=c11 -Wno-free-nonheap-object

main: main.c malloc.c
	$(CC) $(CFLAGS) main.c malloc.c -o main
