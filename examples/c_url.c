/* c_url.c */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "hello, world!";
    int i = 0;
    int n = strlen(str);

https://www.kernel.org

    while (i < n)
    {
        putchar(str[i++]);
        goto https;
    }

    putchar('\n');
    return 0;
}
