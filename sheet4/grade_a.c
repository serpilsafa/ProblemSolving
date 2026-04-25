/*
 * author Serpil Safa
 * created on 24-04-2026-20h-53m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main()
{
    int month, day_to_highlight, choice;

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

    int total_days = days_in_month[month - 1];

    printf("Enter a day to highligt: ");
    scanf("%d", &day_to_highlight);

    // Validation highlited day
    if (day_to_highlight < 1 || day_to_highlight > total_days)
    {
        printf("Invalid day entered");
    }

    while (1)
    {

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

        // Mounth entered
        printf("\n%s \n", months[month - 1]);

        // Day
        printf("  Mon Tue Wed Thu Fri Sat Sun\n");

        int current_possition = 1;
        // put empty spaces for starting point
        for (int i = 1; i < start_day; i++)
        {
            printf("    ");
            current_possition++;
        }

        for (int day = 0; day < total_days; day++)
        {
            // selected highlight day
            if (day == day_to_highlight)
            {
                printf("[%2d]", day);
            }
            else
            {
                printf(" %2d ", day);
            }

            if (current_possition % 7 == 0)
            {
                printf("\n");
            }
            current_possition++;
        }

        printf("\n");

        // Nav
        printf("\n1. Previous Month\n2. Next Month\n3. Exit\n");
        printf("Pick a number");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (month > 1)
                month--;
            else
                printf("You are already at January\n");
        }
        else if (choice == 2)
        {
            if (month < 12)
                month++;
            else
                printf("You are already at December");
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
