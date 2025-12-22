/*
 * pdf.c 
 * Read first 4 bytes of a file to determine if the file is a PDF
 * uint8_t is an unsigned integer type that is 8 bits (1 byte) wide
 */

#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./pdf FILE.PDF\n");
        return 1;
    }

    /* Open file in read mode and check that the file exists */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open file: %s\n", argv[1]);
        return 2;
    }

    /* Create 4 byte buffer */
    uint8_t buffer[4];

    /* Create array of the 4 signature bytes to check (%PDF) */
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    /* Read first 4 bytes from the file */
    fread(buffer, sizeof(uint8_t), 4, file);

    /* Check the first 4 byes of the file */
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("File is not a valid PDF file\n");
            return 3;
        }
    }

    /* Success */
    printf("File is a valid PDF\n");

    /* Close file */
    fclose(file);

    return 0;
}
