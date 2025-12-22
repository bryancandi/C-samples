/*
 * cp.c 
 * Create a copy of a file in binary mode
 */

#include <stdint.h>
#include <stdio.h>

/* Define BYTE as an 8-bit unsigned integer */
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
    {
        printf("Usage: %s SOURCE DEST\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");  /* open source file and read as binary */
    if (src == NULL)
    {
        printf("%s: Source file '%s' does not exist\n", argv[0], argv[1]);
        return 2;
    }

    FILE *dst = fopen(argv[2], "wb");  /* open destination file and write as binary */
    if (dst == NULL)
    {
        printf("%s: Cannot create destination file '%s'\n", argv[0], argv[2]);
        return 3;
    }

    BYTE b;

    /*
     * Read one byte at a time from source and write it to destination.
     * Loop continues as long as fread successfully reads a byte, and terminates
     * when it reaches the end of the file or encounters an error (returns 0).
     */
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);

    return 0;
}
