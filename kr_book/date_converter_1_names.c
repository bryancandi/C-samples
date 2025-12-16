/*
 * Sample 5.8
 * Multi-dimensional arrays
 * Initialization of pointer arrays
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);
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

    printf("Day of year: %d\n\n", day_of_year(year, month, day));

    /* month_day */
    printf("Enter year: ");
    get_input(&year);
    printf("Enter day of year: ");
    get_input(&yearday);

    month_day(year, yearday, &out_month, &out_day);
    printf("Month/day: %s, %d\n", month_name(out_month), out_day);

    return 0;
}

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
    {
        day += daytable[leap][i];
    }
    return day;
}

/* month_day: set month and day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytable[leap][i]; i++)
    {
        yearday -= daytable[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}

/* month_name: return name of n-th month using a pointer array */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

/* get_input: get user input */
void get_input(int *n)
{
    scanf("%d", n);
}
