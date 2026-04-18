/*
 * author Serpil Safa
 * created on 18-04-2026-08h-04m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>
#include <ctype.h> // using for upper case (toupper)

int main(int argc, char const *argv[])
{

    char continou = 'Y';
    char choice;

    while (continou == 'y' || continou == 'Y')
    {
        printf("\n---- City Aquarium Ticketing Menu ----\n");
        printf("1. Book Tickets \n");
        printf("2. View Ticket Prices \n");
        printf("3. Exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 3:
            printf("Exiting program...\n");
            return 0;
        case 2:
            printf("\n---- Ticket Prices ----\n");
            printf("Sharks   - Standard: £22 | Express: £32 \n");
            printf("Reefs    - Standard: £18 | Express: £28 \n");
            printf("Penguins - Standard: £16 | Express: £26 \n");
            break;
        case 1:
            // Variable
            char zone;
            char ticket_type;
            float ticket_price = 0.0;

            int tickets;
            float total_coast;

            char auido_guide;
            float discount = 0;
            float add_on_cost;
            float final_total;

            // User input for zone
            printf("Select zone (S = Sharks, R = Reefs, P = Penguins): ");
            scanf(" %c", &zone);
            zone = toupper(zone);

            if (zone != 'S' && zone != 'P' && zone != 'R')
            {
                printf("Invalid zone. \n");
                return 1;
            }

            // User input for ticket type
            printf("Select ticket type ( N = Standard, E = Express): ");
            scanf(" %c", &ticket_type);
            ticket_type = toupper(ticket_type);

            if (ticket_type != 'N' && ticket_type != 'E')
            {
                printf("Invalid ticket type. \n");
                return 1;
            }

            // User input about tickets
            printf("Enter the number of tickets: ");
            scanf("%d", &tickets);

            // Validation
            if (tickets <= 0)
            {
                printf("Error: Number of tickets must be greater then 0");
                return 1;
            }

            printf("Do you want an audio guide? (y/n)");
            scanf(" %c", &auido_guide);

            // Switch statement for pricing
            switch (zone)
            {
            case 'S': // Sharks
                ticket_price = (ticket_type == 'N') ? 22 : 32;
                break;
            case 'R': // Reefs
                ticket_price = (ticket_type == 'N') ? 18 : 28;
                break;
            case 'P': // Penguins
                ticket_price = (ticket_type == 'N') ? 16 : 26;
                break;
            }

            // Total coast before discount
            total_coast = ticket_price * tickets;

            // Bulk discount
            if (tickets > 5)
            {
                discount = total_coast * 0.15;
            }

            // Add-on cost
            auido_guide = toupper(auido_guide);
            if (auido_guide == 'Y')
            {
                add_on_cost = tickets * 4.50;
            }

            // final total
            final_total = total_coast - discount + add_on_cost;

            // Write to terminal
            printf("\n ---- Booking Aquarium Tickets Summery ----\n");

            if (zone == 'S')
                printf("Zone: Sharks \n");
            else if (zone == 'P')
                printf("Zone: Penguins \n");
            else if (zone == 'R')
                printf("Zone: Reefs \n");

            if (ticket_type == 'N')
            {
                printf("Ticket Type: Standard\n");
            }
            else
            {

                printf("Ticket Type: Express\n");
            }

            printf("Number of tickets: %d \n", tickets);
            printf("Total cost before discount: £%.2f\n", total_coast);
            printf("Add-on cost: £%.2f\n", add_on_cost);
            printf("Final total: £%.2f\n", final_total);

            break;
        default:
            printf("Invalid menu choice.\n");
            break;
        }

        // Repeat menu
        printf("\n Do you want to return menu? (y/n)");
        scanf(" %c", &continou);
    }

    return 0;
}
