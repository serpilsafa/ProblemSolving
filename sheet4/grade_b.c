/*
 * author Serpil Safa
 * created on 24-04-2026-18h-22m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int month;

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

    // Validation
    if (month < 1 || month > 12)
    {
        printf("Invalid month entered");
        return 1;
    }

    // 1 Jan 2025 = Wed -> 3
    int start_day = 3;

    // Sum all days from selected month
    int total_days_passed = 0;
    for (int i = 0; i < month - 1; i++)
    {
        total_days_passed += days_in_month[i];
    }

    // Calculate starting date
    int offset = total_days_passed % 7;
    start_day = ((start_day + offset - 1) % 7) + 1;

    int total_days = days_in_month[month - 1];

    // Mounth entered
    printf("\n%s \n", months[month - 1]);
    printf("Starts on weekday: %d\n", start_day);

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
