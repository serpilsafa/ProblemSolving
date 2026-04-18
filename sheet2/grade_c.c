/*
 * author Serpil Safa
 * created on 14-04-2026-14h-51m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Variable
    char zone;        // S = Sharks, R = Reefs, P = Penguins
    char ticket_type; // N = Standard, E = Express
    float ticket_price = 0.0;

    int tickets;
    float total_coast;

    // User input for zone
    printf("Select zone (S = Sharks, R = Reefs, P = Penguins): ");
    scanf(" %c", &zone);

    // User input for ticket type
    printf("Select ticket type ( N = Standard, E = Express): ");
    scanf(" %c", &ticket_type);

    // User input about tickets
    printf("Enter the number of tickets: ");
    scanf("%d", &tickets);

    // Validation
    if (tickets <= 0)
    {
        printf("Error: Number of tickets must be greater then 0");
        return 1;
    }

    // Switch statement for pricing
    switch (zone)
    {
    case 'S': // Sharks
        switch (ticket_type)
        {
        case 'N': // Standard
            ticket_price = 22.00;
            break;
        case 'E': // Express
            ticket_price = 32.00;
            break;
        default:
            printf("Invalid Ticket type. \n");
            return 1;
        }
        break;
    case 'R': // Reefs
        switch (ticket_type)
        {
        case 'N':
            ticket_price = 18.00;
            break;
        case 'E':
            ticket_price = 28.00;
            break;
        default:
            printf("Invalid Ticket type. \n");
            return 1;
        }
        break;
    case 'P': // Penguins
        switch (ticket_type)
        {
        case 'N':
            ticket_price = 16.00;
            break;
        case 'E':
            ticket_price = 26.00;
            break;
        default:
            printf("Invalid ticket type. \n");
            return 1;
        }
        break;
    default:
        printf("Invalid zone selected. \n");
        return 1;
    }

    total_coast = ticket_price * tickets;

    // Write to terminal
    printf("\n ---- Booking Aquarium Tickets Summery ----\n");

    if (zone == 'S')
        printf("Zone: Sharks \n");
    else if (zone == 'P')
        printf("Zone: Penguins \n");
    else if (zone == 'R')
        printf("Zone: Reefs \n");

    switch (ticket_type)
    {
    case 'N':
        printf("Ticket Type: Standard\n");
        break;
    case 'E':
        printf("Ticket Type: Express\n");
        break;
    default:
        break;
    }
    printf("Tickets: %d \n", tickets);
    printf("Total Cost: £%.2f\n", total_coast);

    return 0;
}
