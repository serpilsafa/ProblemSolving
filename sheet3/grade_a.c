/*
 * author Serpil Safa
 * created on 21-04-2026-14h-03m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

// Function to safely get possitive float num
float getPositiveFloat(const char *message)
{
    float value;
    int valid;

    do
    {
        printf("%s", message);
        valid = scanf("%f", &value);

        if (valid != 1 || value <= 0)
        {
            printf("Invalid input. Please enter a possitive number \n");
            while (getchar() != '\n')
                ; // clear buffer
        }
    } while (valid != 1 || value <= 0);

    return value;
}

// func to safely get menu choice
int getMenuChoice()
{
    int choice, valid;

    do
    {
        printf("\n1: Mililitres \n2: Bootles(500ml) \n3: Cups (240 ml)\n Choice:  ");
        valid = scanf("%d", &choice);

        if (valid != 1 || choice < 1 || choice > 3)
        {
            printf("Invalid choice. Try again.\n");
            while (getchar() != '\n')
                ;
        }
    } while (valid != 1 || choice < 1 || choice > 3);

    return choice;
}

int main()
{
    float goal_litre = getPositiveFloat("Enter daily hydration goal (litres): ");
    float goal_ml = goal_litre * 1000;

    float total_all_days = 0;
    int days = 0, days_met_goal = 0;
    int longest_streak = 0, current_streak = 0;

    char cont_day;

    // env factor
    int env;
    float factor = 1.0;

    do
    {
        printf("\nEnvironment:\n 1: Cool/Indoor\n 2: Warm/Active\n 3: Hot/Very Active\n Choice: ");
        scanf("%d", &env);

        if (env == 2)
            factor = 1.1;
        else if (env == 3)
            factor = 1.2;
        else if (env != 1)
            printf("Invalid choice.\n");
    } while (env < 1 || env > 3);

    goal_ml *= factor;

    do
    {
        char count_entry;
        float daily_total = 0;

        printf("\n -- Day %d --", days + 1);

        do
        {
            int choice = getMenuChoice();
            float amount;

            if (choice == 1)
            {
                amount = getPositiveFloat("Enter ml:  ");
                daily_total += amount;
            }
            else if (choice == 2)
            {
                amount = getPositiveFloat("How many bottless?: ");
                daily_total += amount * 500;
            }
            else
            {
                amount = getPositiveFloat("How many cups?: ");
                daily_total += amount * 240;
            }

            // Pogress
            float progress = (daily_total / goal_ml) * 100;
            printf("Today's progress: %.2f%%\n", progress);

            printf("Add another entry for today? (y/n): ");
            scanf(" %c", &count_entry);

        } while (count_entry == 'y' || count_entry == 'Y');

        // Day summary
        printf("Day %d total: %.0f ml (%.2f L)\n", days + 1, daily_total);

        total_all_days += daily_total;
        days++;

        // Goal check
        if (daily_total >= goal_ml)
        {
            days_met_goal++;
            current_streak++;
            if (current_streak > longest_streak)
                longest_streak = current_streak;
        }
        else
        {
            current_streak = 0;
        }

        printf("Add another day (y/n): ");
        scanf(" %c", &cont_day);

    } while (cont_day == 'y' || cont_day == 'Y');

    // FInal summary
    printf("\n---Final Summary---\n");
    printf("Days tracked: %d\n", days);
    printf("Total intake: %.0f ml (%.2f L)\n", total_all_days, total_all_days / 1000);
    printf("Days meeting goal: %d\n", days_met_goal);
    printf("Longest streak: %d days\n", longest_streak);

    return 0;
}