/*
 * Exercise 5-10
 * Reverse Polish Notation calculator; command-line arg version
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100   /* max depth of value stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

void push(double);
double pop(void);
void mathfnc(char []);
void clear(void);

/* Reverse Polish Calculator */
int main(int argc, char *argv[])
{
    double op2;

    if (argc < 2) {
        printf("Usage: %s <RPN expression>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];

        if (strcmp(arg, "+") == 0) {
            push(pop() + pop());
        } else if (strcmp(arg, "-") == 0) {
            op2 = pop();
            push(pop() - op2);
        } else if (strcmp(arg, "*") == 0) {
            push(pop() * pop());
        } else if (strcmp(arg, "/") == 0) {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
        } else if (strcmp(arg, "%") == 0) {
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
        } else if (strcmp(arg, "c") == 0) {
            clear();
        } else if (isdigit(arg[0]) || (arg[0] == '-' && isdigit(arg[1]))) {
            push(atof(arg));
        } else {
            mathfnc(arg);  /* sin, cos, pow, etc. */
        }
    }

    /* print the final result */
    if (sp > 0)
        printf("\t%.8g\n", pop());
    else
        printf("error: stack empty\n");

    return 0;
}

/* push: push f onto value stack */
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

/* pop: pop and return top value from stack */
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

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
    double op2;

    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0)
    {
        push(cos(pop()));
    }
    else if (strcmp(s, "exp") == 0)
    {
        push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
    {
        printf("error: %s not supported\n", s);
    }
}

/* clear: clear the stack */
void clear(void)
{
    sp = 0;
}
