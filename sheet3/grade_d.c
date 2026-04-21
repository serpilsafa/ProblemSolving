/*
 * author Serpil Safa
 * created on 20-04-2026-09h-31m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main()
{
    float ml, litres, cups;

    // Prompt user to enter daily water intake in millilitres
    printf("Enter water intake for today (ml): ");
    scanf("%f", &ml);

    // Convert millilitres to litres
    litres = ml / 1000.0;

    // Convert millilitres to cups (240 ml per cup)
    cups = ml / 240.0;

    // Terminal showing
    printf("Litres: %.2f L\n", litres);
    printf("Cups (240 ml): %.2f cups\n", cups);

    return 0;
}