/*
 * author Serpil Safa
 * created on 14-04-2026-14h-51m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Variable with fixed default value
    char zone = 'R';        // S = Sharks, R = Reefs, P = Penguins
    char ticket_type = 'E'; // N = Standard, E = Express
    float ticket_price = 0.0;

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
            break;
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
            break;
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
            break;
        }
        break;
    default:
        printf("Invalid zone selected. \n");
        return 1;
    }

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
    printf("Ticket Price: £%.2f\n", ticket_price);

    return 0;
}
