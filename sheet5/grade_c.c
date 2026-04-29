/*
 * author Serpil Safa
 * created on 25-04-2026-18h-36m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{

    int days, choice;
    float temperatures[30], sum = 0, average;
    float highest, lowest;

    // Ask to user number of days
    printf("How many days do want to add -max 30 days: ");
    scanf("%d", &days);

    if (days > 30 || days <= 0)
    {
        printf("Invalid number of days\n");
        return 0;
    }

    // Input temperatures
    for (int i = 0; i < days; i++)
    {
        printf("Enter temperature for day %d :", i + 1);
        scanf("%f", &temperatures[i]);
    }

    // Menu
    while (1)
    {
        printf("\n======MENU=======\n");
        printf("1. Display all temperature\n");
        printf("2. Calculate average temperature\n");
        printf("3. Find highest and lowest temputere\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Recorded Temperature:\n");
            for (int i = 0; i < days; i++)
            {
                printf("Day %d: %.2f°C\n", i + 1, temperatures[i]);
            }
            break;

        case 2:
            sum = 0;
            for (int i = 0; i < days; i++)
            {
                sum += temperatures[i];
            }
            average = sum / days;
            printf("\nAverage Temperature: %.2f°C\n", average);

            break;

        case 3:
            highest = temperatures[0];
            lowest = temperatures[0];

            for (int i = 0; i < days; i++)
            {
                if (temperatures[i] > highest)
                {
                    highest = temperatures[i];
                }

                if (temperatures[i] < lowest)
                {
                    lowest = temperatures[i];
                }
            }

            printf("\nHighest Temperature: %.2f°C\n", highest);
            printf("\nLowest Temperature: %.2f°C\n", lowest);

            break;
        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }

    return 0;
}
