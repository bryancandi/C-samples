/* Exercise 1-13 */

#include <stdio.h>

/* print histogram the length of the words entered */
int main(void)
{
    int c, h;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\n' &&  c != '\t')
        {
            printf("-");
        }
        if (c == '\n')
        {
            printf("\n");
        }
    }
}
