/* Print the size of BUFSIZ on the current machine */

#include <stdio.h>

int main(void)
{
    printf("BUFSIZ is %zu bytes\n", (size_t)BUFSIZ);
    return 0;
}
