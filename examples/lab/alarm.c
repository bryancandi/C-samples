/*
 * ALARM.C - Command-line alarm clock for Linux.
 *
 * The alarm sounds at the next occurrence of the target time.
 * The alarm tone repeats for 400 cycles.
 *
 * Depends on the 'sox' package to generate the alarm tone.
 *
 * Author: Bryan C.
 * Date:   2026-05-06
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ERROR_TIME -1
#define SIZE 64

int get_target_time(void)
{
    int hh, mm;
    char input_time[SIZE];

    if ((fgets(input_time, sizeof(input_time), stdin)) != NULL)
    {
        if (!isdigit(input_time[0]) || !isdigit(input_time[1]))
        {
            return ERROR_TIME;
        }
        if (input_time[2] != ':')
        {
            return ERROR_TIME;
        }
        if (!isdigit(input_time[3]) || !isdigit(input_time[4]))
        {
            return ERROR_TIME;
        }
        if (input_time[5] != '\n' && input_time[5] != '\0')
        {
            return ERROR_TIME;
        }
        hh = ((input_time[0] - '0') * 10) + (input_time[1] - '0');  // convert HH to integer
        mm = ((input_time[3] - '0') * 10) + (input_time[4] - '0');  // convert MM to integer

        if (hh > 23 || mm > 59)
        {
            return ERROR_TIME;
        }

        return (hh * 100) + mm;  // return HHMM format
    }

    return ERROR_TIME;
}

int get_local_time(void)
{
    time_t t;
    struct tm *tmp;
    char curr_time_str[SIZE];

    t = time(NULL);
    tmp = localtime(&t);
    if (tmp == NULL)
    {
        return ERROR_TIME;
    }

    if (strftime(curr_time_str, sizeof(curr_time_str), "%H%M", tmp) == 0)
    {
        return ERROR_TIME;
    }

    return atoi(curr_time_str);
}

void sound_alarm(void)
{
    for (int i = 0, n = 400; i < n; i++)
    {
        system("play -n synth 0.5 sine 440 2> /dev/null");
        sleep(1);
    }
}

int main(void)
{   
    int target_time, local_time;
    const char *app_banner = "ALARM v1.0";
    const char *invalid_time = "Invalid time format. Use 24h HH:MM.";
    const char *local_time_error = "Unable to retrieve local time.";
    const char *lbl_target = "Alarm set time: ";
    const char *lbl_local = "Current time:   ";
    const char *wake = "Alarm!";
    const char *done = "Alarm completed.";

    printf("%s\n\n", app_banner);
    printf("Enter alarm target time (HH:MM): ");

    if ((target_time = get_target_time()) == ERROR_TIME)
    {
        fprintf(stderr, "%s\n", invalid_time);
        return ERROR_TIME;
    }
    if ((local_time = get_local_time()) == ERROR_TIME)
    {
        fprintf(stderr, "%s\n", local_time_error);
        return ERROR_TIME;
    }

    printf("\n%s%04d\n", lbl_target, target_time);
    printf("\r%s%04d", lbl_local, local_time);

    while (local_time != target_time)
    {
        local_time = get_local_time();
        printf("\r%s%04d", lbl_local, local_time);
        fflush(stdout);
        sleep(5);
    }

    printf("\n\n%s\n", wake);
    sound_alarm();
    printf("%s\n", done);

    return 0;
}
