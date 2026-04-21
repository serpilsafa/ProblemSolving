/*
 * author Serpil Safa
 * created on 21-04-2026-08h-02m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main()
{
    float ml, litres, cups;
    float total_ml = 0, amount;
    int days = 0;
    char choice;
    int menu_choice;

    // counter for each type
    int ml_count = 0, bottle_count = 0, cup_count = 0;

    // Loop for multiple days
    do
    {
        // Prompt user to enter daily water intake in millilitres
        printf("\nWhat would you like to add?\n");
        printf("1: Millilitres\n");
        printf("2: Bottles (500 ml each)\n");
        printf("3: Cups (240 ml each)\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice)
        {
        case 1:
            // Input in millilitres
            printf("Enter amount in ml: ");
            scanf("%f", &amount);
            total_ml += amount;
            ml_count++;
            printf("Added %.0f ml.\n", amount);
            break;

        case 2:
            // Input in bottle
            printf("How many bottles? ");
            scanf("%f", &amount);
            total_ml += amount * 500;
            bottle_count++;
            printf("Added %0.f ml. \n", amount * 500);
            break;

        case 3:
            // Input in cups
            printf("How many cups? ");
            scanf("%f", &amount);
            total_ml += amount * 240;
            cup_count++;
            printf("Added %0.f ml.\n", amount * 240);
            break;

        default:
            printf("Invalid choice, Please try again.");
            break;
        }

        // Ask user if the user want to continiue
        printf("\nAdd other day? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // After while summery
    printf("\nSummary:\n");
    printf("Total: %.0f ml (%.2f L) \n", total_ml, total_ml / 1000);
    printf("Entries - Bottles: %d, Cups: %d, Millilitres: %d \n", bottle_count, cup_count, ml_count);

    return 0;
}