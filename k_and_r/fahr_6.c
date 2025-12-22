/*
 * Exercise 1-4
 * Celsius to Fahr
 */

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit */
    upper = 150;  /* upper limit */
    step = 10;    /* step size */

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
