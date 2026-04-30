/*
 * author Serpil Safa
 * created on 30-04-2026-06h-29m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* creating an array of book titles
    mixed alphebetical order */

    char *books[] = {
        "North Passage",
        "Echoes of the Atrium",
        "Archive Key",
        "Silent Horizon",
        "Broken Compass",
        "Velvet Sky",
        "Crimson Letters",
        "Golden Tides"};

    int size = 8;

    // Loop through array
    for (int i = 0; i < size; i++)
    {
        printf("Current Title: \"%s\"\n", books[i]);
        printf("First Title: \"%s\"\n\n", books[0]);
    }

    return 0;
}