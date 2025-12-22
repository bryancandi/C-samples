/* count.c */

#include <stdio.h>

#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */

int main(void)
{
    printf("Type one or more sentences followed by Enter.\n");
    printf("To end input, press Ctrl+D (Linux) or Ctrl+Z (Windows) followed by Enter.\n\n");
    
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("Lines: %d\nWords: %d\nChars: %d\n", nl, nw, nc);
}
