/*
 * main.c
 * main function for the #define processor program
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "macro.h"

#define MAXWORD 100

/* simple version of #define processor; read and process input */
int main(void)
{
    char w[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];

    while (getword(w, MAXWORD) != EOF)
    {
        if (strcmp(w, "#") == 0)  /* beginning of macro */
        {
            getword(w, MAXWORD);
            if (strcmp(w, "define") == 0)  /* word is "define" */
            {
                /* get macro name */
                if (getword(name, MAXWORD) == EOF)
                {
                    break;
                }
                /* get replacement text */
                if (getword(defn, MAXWORD) == EOF)
                {
                    break;
                }
                /* install to hash table */
                install(name, defn);
            }
            else if (strcmp(w, "undef") == 0)  /* word is "undef" */
            {
                if (getword(name, MAXWORD) == EOF)
                {
                    break;
                }
                /* remove from hash table */
                undef(name);
            }
        }
        else if (strcmp(w, "!") == 0)  /* beginning of command */
        {
            getword(w, MAXWORD);
            if (strcmp(w, "print") == 0)  /* !print to print all currently defined macros */
            {
                print_hashtab();
            }
        }
        else  /* print replaced words */
        {
            Nlist *np = lookup(w);
            if (np != NULL)
                printf("%s is defined as: %s\n", np->name, np->defn);
            else
                printf("not defined: %s\n", w);
        }
    }
    return 0;
}
