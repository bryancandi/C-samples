/* Exercise 2-1 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Using headers:\n");
    printf("CHAR MIN: %d\n", CHAR_MIN);
    printf("CHAR MAX: %d\n", CHAR_MAX);
    printf("UCHAR MAX: %u\n", UCHAR_MAX);
    printf("SHORT MIN: %d\n", SHRT_MIN);
    printf("SHORT MAX: %d\n", SHRT_MAX);
    printf("USHRT MAX: %u\n", USHRT_MAX);
    printf("INT MIN: %d\n", INT_MIN);
    printf("INT MAX: %d\n", INT_MAX);
    printf("UINT MAX: %u\n", UINT_MAX);
    printf("LONG MIN: %ld\n", LONG_MIN);
    printf("LONG MAX: %ld\n", LONG_MAX);
    printf("ULONG MAX: %lu\n", ULONG_MAX);

    printf("\nComputed directly:\n");
    printf("Signed char:   %d to %d\n",
           -(1 << (sizeof(char)*8 - 1)),
           (1 << (sizeof(char)*8 - 1)) - 1);
    printf("Unsigned char:  0 to %u\n", (unsigned char)~0);

    printf("Signed short:  %d to %d\n",
           -(1 << (sizeof(short)*8 - 1)),
           (1 << (sizeof(short)*8 - 1)) - 1);
    printf("Unsigned short: 0 to %u\n", (unsigned short)~0);

    printf("Signed int:    %d to %d\n",
           (int)(-(1U << (sizeof(int)*8 - 1))),
           (int)((1U << (sizeof(int)*8 - 1)) - 1));
    printf("Unsigned int:   0 to %u\n", (unsigned)~0);

    printf("Signed long:   %ld to %ld\n",
           (long)(-(1UL << (sizeof(long)*8 - 1))),
           (long)((1UL << (sizeof(long)*8 - 1)) - 1));
    printf("Unsigned long:  0 to %lu\n", (unsigned long)~0UL);

    return 0;
}
