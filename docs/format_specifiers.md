### C Format Specification Syntax

#### Format Specifiers

| Character | Argument type | Printed as |
| ---- | ---- | ---- |
| c    | `int` | A single character. |
| d, i | `int` | A decimal integer. |
| o    | `unsigned int` | An unsigned octal integer (without leading 0). |
| u    | `unsigned int` | An unsigned decimal integer. |
| x, X | `unsigned int` | An unsigned hexadecimal number (without a leading 0x or 0X), using `abcdef` or `ABCDEF` for 10, ..., 15. |
| e, E | `double` | [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision (default 6). |
| f, F | `double` | [-]m.dddddd, where the number of d's is given by the precision (default 6). |
| g, G | `double` | Use %e or %E if the exponent is less than -4 or greater than or equal to the precision; otherwise use %f. Trailing zeros and a trailing decimal point are not printed. |
| a, A | `double` | Hexadecimal floating-point notation: [-]0xh.hhhhp±d (exponent is base 2). |
| p    | `void *` | Pointer. Displays the argument as an implementation-defined character sequence (commonly a hexadecimal address). |
| n    | `int *` | Stores the number of characters written so far into the integer pointed to by the argument. |
| s    | `char *` | Pointer to a null-terminated character string. |

#### ISO C99+ length modifiers

| Prefix | Use to specify | With type |
| ---- | ---- | ---- |
| hh | `signed char` or `unsigned char` | `d`, `i`, `o`, `u`, `x`, or `X` |
| h  | `short int` or `short unsigned int` |`d`, `i`, `o`, `u`, `x`, or `X` |
| l  | `long int` or `long unsigned int` | `d`, `i`, `o`, `u`, `x`, or `X` |
| ll | `long long int` or `unsigned long long int` | `d`, `i`, `o`, `u`, `x`, or `X` |
| j  | `intmax_t` or `uintmax_t` | `d`, `i`, `o`, `u`, `x`, or `X` |
| z  | `size_t` | `d`, `i`, `o`, `u`, `x`, or `X` |
| t  | `ptrdiff_t` | `d`, `i`, `o`, `u`, `x`, or `X` |
| L  | `long double` | `a`, `A`, `e`, `E`, `f`, `F`, `g`, or `G` |

#### Microsoft length modifiers (extensions)

| Prefix | Use to specify | With type |
| ---- | ---- | ---- |
| I32 | `__int32` or `unsigned __int32` | `d`, `i`, `o`, `u`, `x`, or `X` |
| I64 | `__int64` or `unsigned __int64` | `d`, `i`, `o`, `u`, `x`, or `X` |
| I   | `__int32` or `__int64` | `d`, `i`, `o`, `u`, `x`, or `X` |
| LL  | `__int64` (LONGLONG) | `d`, `i`, `o`, `u`, `x`, or `X` |
| w   | wide-character | `s`, `S`, or `Z` |
