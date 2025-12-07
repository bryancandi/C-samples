/* Sample 7.1
 * lower: convert input to lower case (using library function)
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(tolower(c));
    }
    return 0;
}
