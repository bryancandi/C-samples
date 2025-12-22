/*
 * Exercise 5-4
 * strend: return 1 if string t occurs at the end of string s; zero otherwise
 */

#include <stdio.h>

int strend(char *s, char *t);

int main(void)
{
    char *s = "Hello, world";
    char *t = "world";

    if (strend(s, t) == 1)
    {
        printf("String s ends with string t\n");
    }
    else
    {
        printf("String s does not end with string t\n");
    }
    
    return 0;
}

int strend(char *s, char *t)
{
    int len_s = 0;
    int len_t = 0;

    /* pointers to advance to check string lengths */
    char *s_ptr = s;
    char *t_ptr = t;

    /* get string lengths */
    while (*s_ptr++ != '\0')
    {
        len_s++;
    }
    while (*t_ptr++ != '\0')
    {
        len_t++;
    }

    /* make sure string s is larger than string t */
    if (len_t > len_s)
    {
        return 0;
    }

    /* set starting position in s to where t would start */
    s = s + (len_s - len_t);

    while (*s && *t)
    {
        if (*s++ != *t++)
        {
            return 0;  /* no match */
        }
    }

    return 1;  /* match */
}
