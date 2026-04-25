/*
 * author Serpil Safa
 * created on 24-04-2026-14h-58m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int month, start_day;

    // Mounth names
    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};

    // day number for 2025
    int days_in_month[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    // User input
    printf("1=January, 2=February, 3=March, 4=April, 5=May, 6=June\n");
    printf("7=July, 8=August, 9=September,10=October, 11=November, 12=December\n");
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("\n1=Mon, 2= Tue, 3=Wed, 4=Thr, 5=Fri, 6=Sat, 7=Sun\n");
    printf("Enter starting weekday (1-7): ");
    scanf("%d", &start_day);

    // Validation
    if (month < 1 || month > 12)
    {
        printf("Invalid month entered");
        return 1;
    }

    if (start_day < 1 || start_day > 7)
    {
        printf("Invalid starting day entered");
        return 1;
    }

    int total_days = days_in_month[month - 1];

    // Mounth entered
    printf("\n%s \n", months[month - 1]);

    // Day
    printf("  Mon Tue Wed Thu Fri Sat Sun\n");

    int current_possition = 1;
    int saturday_count = 0;
    int sunday_count = 0;

    // put empty spaces for starting point
    for (int i = 1; i < start_day; i++)
    {
        printf("    ");
        current_possition++;
    }

    // print days
    for (int day = 1; day <= total_days; day++)
    {
        printf(" %3d", day);
        if (current_possition % 7 == 6) // Saturday
        {
            saturday_count++;
        }

        if (current_possition % 7 == 0) // Sunday and new line
        {
            sunday_count++;
            printf("\n");
        }
        current_possition++;
    }

    printf("\nSaturdays: %d\n", saturday_count);
    printf("Sundays: %d\n ", sunday_count);

    return 0;
}
