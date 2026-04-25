/*
 * author Serpil Safa
 * created on 21-04-2026-19h-16m
 * github: https://github.com/serpilsafa/ProblemSolving
 * copyright 2026
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int month, start_day;

    // Mounth names
    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};

    // User input
    printf("1=January, 2=February, 3=March, 4=April, 5=May, 6=June\n");
    printf("7=July, 8=August, 9=September,10=October, 11=November, 12=December\n");
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("\n1=Mon, 2= Tue, 3=Wed, 4=Thr, 5=Fri, 6=Sat, 7=Sun\n");
    printf("Enter starting weekday (1-7): ");
    scanf("%d", &start_day);

    int total_days = 30; // fixed day

    // Mounth start
    printf("\n%s \n", months[month - 1]);

    int current_possition = 1;

    // Day
    printf("  Mon Tue Wed Thu Fri Sat Sun\n");

    // put empty space for starting point
    for (int i = 1; i < start_day; i++)
    {
        printf("    ");
        current_possition++;
    }

    for (int day = 1; day <= total_days; day++)
    {
        printf(" %3d", day);
        if (current_possition % 7 == 0)
        {
            printf("\n");
        }
        current_possition++;
    }

    return 0;
}
