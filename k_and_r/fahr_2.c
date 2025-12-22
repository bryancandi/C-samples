/*
 * Sample 1.2
 * Fahr to Celsius: floating-point version
 */

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
