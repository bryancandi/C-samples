/* c_url.c */

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char str[] = "hello, world!";

https://www.kernel.org

    while (i < strlen(str))
    {
        putchar(str[i++]);
        goto https;
    }

    putchar('\n');
    return 0;
}
