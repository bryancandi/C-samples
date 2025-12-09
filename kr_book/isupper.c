/* Exercise 7-9
 * isupper: return 1 (true) if c is an uppercase letter (custom function)
 * macro also exists in <ctype.h>
 */

#include <stdio.h>
#include <string.h>

#define isupper_macro(c) (((c) >= 'A' && (c) <= 'Z') ? 1 : 0)

int isupper(char c);

int main(void)
{
    const char *p = "This Is A String";
    int n = strlen(p);

    printf("Function:\t");
    for (int i = 0; i < n; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c ", p[i]);
        }
    }
    printf("\nMacro   :\t");
    for (int i = 0; i < n; i++)
    {
        if (isupper_macro(p[i]))
        {
            printf("%c ", p[i]);
        }
    }
    return 0;
}

int isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
