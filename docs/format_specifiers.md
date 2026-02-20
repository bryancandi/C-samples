### C Format Specification Syntax

| Character | Argument type; Printed as |
| ----      | ----                      |
| c, C      | `int;` single character   |
| d, i      | `int;` decimal integer    |
| o         | `int;` unsigned octal integer (without leading 0) |
| u         | `int;` unsigned decimal integer |
| x, X      | `int;` unsigned hexadecimal number (without a leading 0x or 0X), using `abcdef` or `ABCDEF` for 10, ..., 15. |
| e, E      | `double;` [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision (default 6). |
| f, F      | `double;` [-]m.dddddd, where the number of d's is given by the precision (default 6). |
| g, G      | `double;`  use %e or %E if the exponent is less than -4 or greater than or equal to the precision; otherwise use %f. Trailing zeros and a trailing decimal point are not printed. |
| p         | `void *;` (pointer) display the argument as an address in hexadecimal digits. |
| n         | `int *;` number of characters that are successfully written so far to the stream or buffer. This value is stored in the integer whose address is given as the argument. |
| s, S      | `char *` (character string) pointing to an array of characters long enough for the string and a terminating '\0' that will be added. |

| Prefix    | With type; To Specify |
| ----      | ----                  |
| h         | `d`, `i`, `o`, `u`, `x`, or `X` for `short int` or `short unsigned int` |
| hh        | `d`, `i`, `o`, `u`, `x`, or `X` for `char` or `unsigned char` |
| I32       | `d`, `i`, `o`, `u`, `x`, or `X` for `__int32` or `unsigned __int32` |
| I64       | `d`, `i`, `o`, `u`, `x`, or `X` for `__int64` or `unsigned __int64` |
| j, I64    | `d`, `i`, `o`, `u`, `x`, or `X` `intmax_t` or `uintmax_t` |
| l, L      | `a`, `A`, `e`, `E`, `f`, `F`, `g`, or `G` for `long double` |
| l         | `d`, `i`, `o`, `u`, `x`, or `X` for `long int` or `long unsigned int` |
| ll, LL    | `d`, `i`, `o`, `u`, `x`, or `X` for `long long int` or `unsigned long long int` |
| t, I      | `d`, `i`, `o`, `u`, `x`, or `X` for `ptrdiff_t` |
| z, I      | `d`, `i`, `o`, `u`, `x`, or `X` for  `size_t` |
