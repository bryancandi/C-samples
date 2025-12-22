/*
 * Exercise 5-8
 * Add error checking
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);
void get_input(int *n);

/* daytable[0] = non-leap year, daytable[1] = leap year */
static char daytable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
    int year, month, day;
    int yearday, out_month, out_day;

    /* day_of_year */
    printf("Enter year: ");
    get_input(&year);
    printf("Enter month: ");
    get_input(&month);
    printf("Enter day: ");
    get_input(&day);

    int doy = day_of_year(year, month, day);
    if (doy < 0)
    {
        printf("Invalid input\n");
        return 1;
    }
    printf("Day of year: %d\n\n", doy);
    

    /* month_day */
    printf("Enter year: ");
    get_input(&year);
    printf("Enter day of year: ");
    get_input(&yearday);

    int md = month_day(year, yearday, &out_month, &out_day);
    if (md < 0)
    {
        printf("Invalid input\n");
        return 1;
    }
    printf("Month: %d, day: %d\n", out_month, out_day);

    return 0;
}

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 1)
    {
        return -1;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12)
    {
        return -1;
    }
    if (day < 1 || day > daytable[leap][month])
    {
        return -1;
    }
    for (i = 1; i < month; i++)
    {
        day += daytable[leap][i];
    }
    return day;
}

/* month_day: set month and day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, j, leap;
    int maxdays = 0;

    if (year < 1)
    {
        return -1;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (j = 1; j < 13; j++)  /* count total days in entered year */
    {
        maxdays += daytable[leap][j];
    }
    if (yearday < 1 || yearday > maxdays)
    {
        return -1;
    }
    for (i = 1; yearday > daytable[leap][i]; i++)
    {
        yearday -= daytable[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
    return 0;
}

/* get_input: get user input with error checking */
void get_input(int *n)
{
    while (scanf("%d", n) != 1)
    {
        printf("Invalid input, try again: ");
        int c;
        while ((c = getchar()) != '\n')
            ;
    }
}
