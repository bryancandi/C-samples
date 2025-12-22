/*
 * calc.h
 * Header for Reverse Polish Notation calculator functions
 */

#ifndef RPN_CALC_H
#define RPN_CALC_H

#define NUMBER '0'  /* signal that a number was found */

void push(double);
double pop(void);
int getop(char []);

#endif  /* RPN_CALC_H */
