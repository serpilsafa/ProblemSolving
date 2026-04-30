/*
 * author Serpil Safa
 * created on 30-04-2026-10h-15m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>
#include <ctype.h>  // for tolower()
#include <string.h> // for strcspn()

// case insesitive comp
int compare(char *i, char *j)
{
    while (*i && *j)
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
    char delete_title[100];
    int found = -1;

    // Orijinal book list
    printf("\n\n");
    printf("Orijinal list: ");
    for (int i = 0; i < size; i++)
    {
        printf("\"%s\"", books[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("\n\n");

    /*  deleting logic
        fgets → safely retrieves input from the user
        strcspn → finds the location of the newline character
        = 0 → terminates (cleans) the string there
    */

    printf("Enter a book title to delete: ");
    fgets(delete_title, sizeof(delete_title), stdin); // always add newline

    delete_title[strcspn(delete_title, "\n")] = 0; // remove newline

    // search input and list value are equal
    for (int i = 0; i < size; i++)
    {
        if (compare(books[i], delete_title) == 0)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
    {
        // shift
        for (int i = found; i < size; i++)
        {
            books[i] = books[i + 1];
        }
        size--;
        printf("Book deleted successfullt.\n");
    }
    else
    {
        printf("Book not found.\n");
    }

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

    // buble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (compare(books[j], books[j + 1]) > 0)
            {
                char *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
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
