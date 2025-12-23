/*
 * cp.c
 * Create a copy of a file in binary mode (cp)
 * Author: Bryan C.
 * Date: December 23, 2025
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* define BYTE as an 8-bit unsigned integer */
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    char *prog = argv[0];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [SRC FILE] [DST FILE]\n", prog);
        exit(1);
    }

    if ((src = fopen(argv[1], "rb")) == NULL) {  /* open source file and read as binary */
        fprintf(stderr, "%s: Source file '%s' does not exist\n", prog, argv[1]);
        exit(2);
    }

    if ((dst = fopen(argv[2], "wb")) == NULL) {  /* open destination file and write as binary */
        fprintf(stderr, "%s: Cannot create destination file '%s'\n", prog, argv[2]);
        fclose(src);  /* src already open, close it */
        exit(3);
    }

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) {
        if (fwrite(&b, sizeof(b), 1, dst) != 1) {
            fprintf(stderr, "%s: write error\n", prog);
            fclose(src);
            fclose(dst);
            exit(4);
        }
    }
    
    if (ferror(src)) {  /* read error */
        fprintf(stderr, "%s: read error\n", prog);
        fclose(src);
        fclose(dst);
        exit(5);
    }

    fclose(dst);
    fclose(src);
    return 0;
}
