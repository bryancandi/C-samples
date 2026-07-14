/*
 * A simple C program that demonstrates data type sizes.
 */

#include <limits.h>
#include <stdio.h>

int main(void)
{
    char                v1;
    unsigned char       v2;
    short               v3;
    short int           v4;
    short unsigned      v5;
    int                 v6;
    unsigned            v7;
    long                v8;
    long int            v9;
    long unsigned       v10;
    long long int       v11;
    long long unsigned  v12;
#if defined(_WIN32)
    __int64             v13; // Windows specific data type
    unsigned __int64    v14; // Windows specific data type
#endif
    float               v15;
    double              v16;
    long double         v17;
    void *              v18;

    printf
    (
        "Data types and sizes on this system:\n\n"
        "Size of char:               %2zu byte   (%zu-bits)\n"
        "Size of unsigned char:      %2zu byte   (%zu-bits)\n"
        "Size of short:              %2zu bytes  (%zu-bits)\n"
        "Size of short int:          %2zu bytes  (%zu-bits)\n"
        "Size of short unsigned:     %2zu bytes  (%zu-bits)\n"
        "Size of int:                %2zu bytes  (%zu-bits)\n"
        "Size of unsigned:           %2zu bytes  (%zu-bits)\n"
        "Size of long:               %2zu bytes  (%zu-bits)\n"
        "Size of long int:           %2zu bytes  (%zu-bits)\n"
        "Size of long unsigned:      %2zu bytes  (%zu-bits)\n"
        "Size of long long int:      %2zu bytes  (%zu-bits)\n"
        "Size of long long unsigned: %2zu bytes  (%zu-bits)\n"
#if defined(_WIN32)
        "Size of __int64:            %2zu bytes  (%zu-bits)\n"
        "Size of unsigned __int64:   %2zu bytes  (%zu-bits)\n"
#else
        "Size of __int64:             Windows specific data type\n"
        "Size of unsigned __int64:    Windows specific data type\n"
#endif
        "Size of float:              %2zu bytes  (%zu-bits)\n"
        "Size of double:             %2zu bytes  (%zu-bits)\n"
        "Size of long double:        %2zu bytes  (%zu-bits)\n"
        "Size of pointer:            %2zu bytes  (%zu-bits)\n",
        sizeof(v1),
        sizeof(v1) * CHAR_BIT,
        sizeof(v2),
        sizeof(v2) * CHAR_BIT,
        sizeof(v3),
        sizeof(v3) * CHAR_BIT,
        sizeof(v4),
        sizeof(v4) * CHAR_BIT,
        sizeof(v5),
        sizeof(v5) * CHAR_BIT,
        sizeof(v6),
        sizeof(v6) * CHAR_BIT,
        sizeof(v7),
        sizeof(v7) * CHAR_BIT,
        sizeof(v8),
        sizeof(v8) * CHAR_BIT,
        sizeof(v9),
        sizeof(v9) * CHAR_BIT,
        sizeof(v10),
        sizeof(v10) * CHAR_BIT,
        sizeof(v11),
        sizeof(v11) * CHAR_BIT,
        sizeof(v12),
        sizeof(v12) * CHAR_BIT,
#if defined(_WIN32)
        sizeof(v13),
        sizeof(v13) * CHAR_BIT,
        sizeof(v14),
        sizeof(v14) * CHAR_BIT,
#endif
        sizeof(v15),
        sizeof(v15) * CHAR_BIT,
        sizeof(v16),
        sizeof(v16) * CHAR_BIT,
        sizeof(v17),
        sizeof(v17) * CHAR_BIT,
        sizeof(v18),
        sizeof(v18) * CHAR_BIT
    );

    return 0;
}
