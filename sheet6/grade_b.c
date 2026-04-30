/*
 * author Serpil Safa
 * created on 30-04-2026-8h-53m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>
#include <ctype.h> // for tolower()

// case insesitive comp
int compare(char *i, char *j)
{
    while (i && j)
    {
        char ci = tolower(*i);
        char cj = tolower(*j);

        if (ci < cj)
            return -1;
        if (ci > cj)
            return 1;

        i++;
        j++;
    }

    return tolower(*i) - tolower(*j);
}

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
    printf("\n\n");
    printf("Before: ");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", books[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("\n\n");

    // sort
    for (int i = 0; i < size; i++)
    {
        int min_index = i;

        // find smallest value in list
        for (int j = i + 1; j < size; j++)
        {
            if (compare(books[j], books[min_index]) < 0)
            {
                min_index = j;
            }
        }

        // swapping
        if (min_index != i)
        {
            char *temp = books[i];
            books[i] = books[min_index];
            books[min_index] = temp;
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
