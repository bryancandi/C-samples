/* Exercise 1-12 */

#include <stdio.h>

/* print words entered one per line */
int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            c = '\n';
        }
        putchar(c);
    }
}
