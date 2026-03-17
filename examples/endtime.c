/*
 * 32-bit time_t maximum value
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t time_max = 0x7FFFFFFF;

    printf("ctime = %s\n", ctime(&time_max));
    printf("gmtime = %s\n", asctime(gmtime(&time_max)));
    return 0;
}
