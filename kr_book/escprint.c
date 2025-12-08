/* Exercise 7-2
 * Print non-printable characters in octal
 * Break long lines
 */

#include <ctype.h>
#include <stdio.h>

#define MAXCOL 80 // maximum column width before line break

int main(void)
{
    int c;
    int col = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n') // reset column count for actual newline
        {
            putchar(c);
            col = 0;
        }
        else if (isprint(c)) // printable character: output as-is, advance column
        {
            putchar(c);
            col++;
        }
        else // non-printable: print as octal escape sequence, advance column by 4 (\ + 3 digits)
        {
            printf("\\%03o", c);
            col += 4;
        }
        if (col >= MAXCOL) // wrap line when column limit is reached, reset column
        {
            putchar('\n');
            col = 0;
        }
    }
    return 0;
}
