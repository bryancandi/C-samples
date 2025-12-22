/*
 *stack.c
 * push: push f onto value stack
 * pop: pop and return top value from stack
 */

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100   /* max depth of value stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
