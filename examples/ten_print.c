/*
 * ten_print.c
 *
 * C version of the classic CBM BASIC “10 PRINT” maze program:
 * 10 PRINT CHR$(205.5+RND(1)); : GOTO 10
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

void sleep_ms(unsigned int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif 
}

#define CHAR1 "\u2571"
#define CHAR2 "\u2572"
#define DELAY 5

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  /* Windows needs UTF-8 code page */
#endif

    srand((unsigned)time(NULL));

    for (;;) {
        sleep_ms(DELAY);
        printf("%s", (rand() % 2) ? CHAR1 : CHAR2);
        fflush(stdout);
    }
}
