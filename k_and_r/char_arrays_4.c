/* Exercise 1-18 */

#include <stdio.h>
#define MAXLINE 1000

int my_getline(char[], int maxline);

/* remove trailing whitespace and tabs from the string and then print */
int main(void)
{
    int len;  /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        /* include quotes to show that the string was trimmed successfully */
        printf("\"%s\"\n", line);
    }
    return 0;
}

/* my_getline: read a line into s, remove trailing blanks and tabs, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    /*
     * while the character left of the null terminator null (s - 1) is space or tab
     * move the null terminator to the left; decrement i
     */
    while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
    {
        s[i - 1] = '\0';
        --i;
    }
    s[i] = '\0';  /* ensure the string is null terminated */
    return i;
}
