/* Exercise 1-19 */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char[], int maxline);
void reverse(char s[]);

/* reverse the order of the string and then print */
int main(void)
{
    int len;  /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse char order in a string */
void reverse(char s[])
{
    int i = 0;
    int j;

    /* find the length of the string; 'i' becomes last character */
    while (s[i] != '\0' && s[i] != '\n')
    {
        ++i;
    }

    /* assign 'j' the last character before newline (i - 1) */
    j = i - 1;
    /* reset 'i' to the beginning of the string (0) */
    i = 0;
    
    /* swap characters from each end */
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];  /* end to beginning */
        s[j] = temp;  /* beginning to end */
        ++i;
        --j;
    }
}
