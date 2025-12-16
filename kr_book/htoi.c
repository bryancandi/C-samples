/* Exercise 2-3 */

#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main(void)
{
    int d = 0;
    char h[] = "0x000fff";  /* change value as needed for testing */

    d = htoi(h);

    printf("%d\n", d);

    return 0;
}

int htoi(char s[])
{
    int i = 0;
    int n;
    int dec = 0;
    int hex = 0;

    /* skip leading '0x' or '0X' */
    if (s[i] == '0')
    {
        i++;
    }
    if (s[i] == 'x' || s[i] == 'X')
    {
        i++;
    }

    /*
     * iterate over the remaining chars and convert to ints by subtracting '0' for numbers and 'A' or 'a' for letters
     * add 10 (decimal) because 'A' or 'a' represents the hexadecimal value 10 (decimal)
     */
    for (n = strlen(s); i < n; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            hex = (s[i] - '0');
            dec = 16 * dec + hex;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            hex = (s[i] - 'A' + 10);
            dec = 16 * dec + hex;
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            hex = (s[i] - 'a' + 10);
            dec = 16 * dec + hex;
        }
    }
    return dec;
}
