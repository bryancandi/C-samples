/* Exercise 1-15 */

#include <stdio.h>

#define LOWER 0    /* lower limit */
#define UPPER 300  /* upper limit */
#define STEP 20    /* step size */

int convert(int fahr);

/* use a function to calculate */
int main(void)
{
    int fahr;
    int celsius;
    
    printf("Fahrenheit to Celsius conversion table:\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        celsius = convert(fahr);
        printf("%3d\t%6d\n", fahr, celsius);
    }
}

/* convert: perform temperature conversions */
int convert(int fahr)
{  
    int celsius = (5.0 / 9.0) * (fahr - 32);
    return celsius;
}
