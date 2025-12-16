/* Exercise 2-4 & 2-5 */

#include <stdio.h>

#define MAXLINE 100

int any(char s1[], char s2[]);
void squeeze(char s1[], char s2[]);

int main(void)
{
    int n;
    char string1[MAXLINE] = "This is a test string";
    char string2[MAXLINE] = "aeiou";

    n = any(string1, string2);
    squeeze(string1, string2);

    printf("First char matched at location: %d\n", n);
    printf("String 1 squeezed: %s\n", string1);

}

/* any: scan s1 for characters in s2 that match; if match is found print location of match */
int any(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++)
            ;

        if (s1[i] == s2[k])
        {
            return i + 1;  /* +1 since the loops are zero indexed */
            break;
        }
    }
    return -1;
}

/* squeeze: delete characters in s1 that are also in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        /*
         * scan s2 to see if s1[i] matches any character
         * loop stops early if a match is found; otherwise k reaches end of s2
         */
        for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++)
            ;
        /*
         * if no match was found in s2 (s2[k] == '\0'), keep s1[i] by copying it to s1[j]
         * advance j (j++) for next loop
         */
        if (s2[k] == '\0')
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
