/*
 * author Serpil Safa
 * created on 25-04-2026-19h-42m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

#define MAX 50 // constant variable defination

int main(int argc, char const *argv[])
{

    float temperatures[MAX]; // temperatures array size assign to max defination
    int count = 0;
    int choice;
    float sum, average, temp;
    float highest, lowest;
    float threshold;
    int above, below;

    // Input using sentinel value which is -1
    printf("Enter tempuratures (enter -1 to stop): \n ");

    for (int i = 0; i < MAX; i++)
    {
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%f", &temp);

        if (temp == -1)
        {
            break; // sentinel value stop input
        }

        temperatures[i] = temp;
        count++;
    }

    // Menu
    while (1)
    {
        printf("\n======MENU=======\n");
        printf("1. Display all temperature\n");
        printf("2. Calculate average temperature\n");
        printf("3. Find highest and lowest temputere\n");
        printf("4. Count days above and below a threshold\n");
        printf("5. Weekly average tempuratures\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Recorded Temperature:\n");
            for (int i = 0; i < count; i++)
            {
                printf("Day %d: %.2f°C\n", i + 1, temperatures[i]);
            }
            break;

        case 2:
            sum = 0;
            for (int i = 0; i < count; i++)
            {
                sum += temperatures[i];
            }
            average = sum / count;
            printf("\nAverage Temperature: %.2f°C\n", average);

            break;

        case 3:
            highest = temperatures[0];
            lowest = temperatures[0];

            for (int i = 0; i < count; i++)
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
            printf("Enter threshold temperature: ");
            scanf("%f", &threshold);

            above = 0;
            below = 0;

            for (int i = 0; i < count; i++)
            {
                if (temperatures[i] > threshold)
                    above++;
                else if (temperatures[i] < threshold)
                    below++;
            }

            printf("\nDays above %.2f°C: %d", threshold, above);
            printf("\nDays below %.2f°C: %d\n", threshold, below);
            break;

        case 5:
            int week = 1;
            int j = 0;
            printf("\nWeekly average:\n");

            while (j < count)
            {
                sum = 0;
                int daysInWeek = 0;

                // process 7 days per week
                for (int i = 0; i < 7 && j < count; i++, j++)
                {
                    sum += temperatures[j];
                    daysInWeek++;
                }

                average = sum / daysInWeek;
                printf("Week %d Average: %.2f°C\n", week, average);
                week++;
            }
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }

    return 0;
}
