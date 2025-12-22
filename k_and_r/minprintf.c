/*
 * Sample 7.3 / Exercise 7-3
 * minprintf: minimal printf with variable argument list
 */

#include <stdarg.h>
#include <stdio.h>

/* declaration ending with '...' means the number and types of arguments may vary */
void minprintf(char *fmt, ...);

int main(void)
{
    char *string = "string";
    int n = 10;
    double d = 10.5;

    /* add more tests or modify existing: */
    minprintf("This is some text...\n");
    minprintf("string: %s\n", string);
    minprintf("int   : %d\n", n);
    minprintf("double: %f\n", d);

    return 0;
}

void minprintf(char *fmt, ...)
{
    va_list ap;  /* will point to argument list after va_start */
    char *p, *sval;
    int ival;
    double dval;
    unsigned oval, uval, xval;

    va_start(ap, fmt);  /* make ap point to first unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch(*++p)
        {
        case 'c':
            putchar(va_arg(ap, int));
            break;
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 'o':
            oval = va_arg(ap, unsigned);
            printf("%o", oval);
            break;
        case 'p':
            printf("%p", va_arg(ap, void *));
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
            {
                putchar(*sval);
            }
            break;
        case 'u':
            uval = va_arg(ap, unsigned);
            printf("%u", uval);
            break;
        case 'x':
            xval = va_arg(ap, unsigned);
            printf("%x", xval);
            break;
        case 'X':
            xval = va_arg(ap, unsigned);
            printf("%X", xval);
            break;
        case '%':
            putchar('%');
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);  /* clean up when done */
}
