/*
 * 10 PRINT (UNIX)
 *
 * "Early C" version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 *
 * Written for Unix Fourth Edition (c. 1973).
 * Use Ctrl+\ (Quit signal) to terminate.
 *
 * Author: Bryan C.
 * Date: 2025-12-29
 */

main()
{
    int i;
    i = 0;
    while (1) {
        putchar("/\\"[(rand() >> 8) & 1]);
        i++;
        if (i % 80 == 0) {
            putchar('\n');
        }
    }
}
