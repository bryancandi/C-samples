/*
 * macro.h
 * header for #define processor program
 */

#ifndef MACRO_H
#define MACRO_H

/* Nlist: hash table entry for a macro (linked list node) */
typedef struct nlist {
    struct nlist *next;  /* next entry in chain */
    char *name;          /* macro name */
    char *defn;          /* replacement text */
} Nlist;

/* macro.c: hash table operations */
unsigned hash(char *s);
Nlist *lookup(char *s);
Nlist *install(char *name, char *defn);
void undef(char *name);
void print_hashtab(void);

/* getword.c: get word or character from input */
int getword(char *, int);

#endif
