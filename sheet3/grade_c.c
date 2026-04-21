/*
 * author Serpil Safa
 * created on 20-04-2026-09h-54m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main()
{
    float ml, litres, cups;
    float total_litres = 0;
    int days = 0;
    char choice;

    // Loop for multiple days
    do
    {
        // Prompt user to enter daily water intake in millilitres
        printf("Enter water intake for today (ml): ");
        scanf("%f", &ml);

        // Convert millilitres to litres
        litres = ml / 1000.0;

        // Convert millilitres to cups (240 ml per cup)
        cups = ml / 240.0;

        // Terminal showing daily
        printf("Litres: %.2f L | Cups (240 ml): %.2f cups\n ", litres, cups);

        // total litres
        total_litres += litres;
        days++;

        // Ask user if the user want to continiue
        printf("Add other day? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // After while summery
    printf("\nYou tracked %d days. Total %.2f L \n", days, total_litres);

    return 0;
}