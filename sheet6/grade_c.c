/*
 * author Serpil Safa
 * created on 30-04-2026-07h-05m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>
#include <string.h> // for strcasecmp

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

    // Before swap
    printf("Before: ");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", books[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("\n\n");

    // Single comporation with index 0
    for (int i = 1; i < size; i++)
    {
        if (strcmp(books[i], books[0]) < 0)
        {
            char *temp = books[0];
            books[0] = books[i];
            books[i] = temp;
        }
    }

    // After
    printf("After: ");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", books[i]);
        if (i < size - 1)
            printf(", ");
    }

    return 0;
}
