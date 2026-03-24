#include <stdio.h>
#include <stdlib.h>

int *get_value_from_user(char day[10])
{
    int *value = malloc(3 * sizeof(int));

    printf("Enter the number of minutes you used for social applications for  %s : \n", day);
    scanf("%d", &value[0]);
    if (value[0] < 0)
    {
        printf("Invalid number");
        return 0;
    }

    printf("Enter the number of minutes you used for video applications for  %s : \n", day);
    scanf("%d", &value[1]);
    if (value[1] < 0)
    {
        printf("Invalid number");
        return 0;
    }

    printf("Enter the number of minutes you used for game applications for %s : \n", day);
    scanf("%d", &value[2]);
    if (value[2] < 0)
    {
        printf("Invalid number");
        return 0;
    }

    return value;
}

int main()
{

    int social, video, game;

    char week[7][10] = {"Monday", "Tuesday", "Wendesday", "Thuersday", "Friday", "Saturday", "Sunday"};
    int *user_value;
    int week1_values[7][3];
    int week2_values[7][3];

    int sum_daily1[7];
    int sum_week1 = 0;
    int avr_weekly1 = 0;

    int sum_daily2[7];
    int sum_week2 = 0;
    int avr_weekly2 = 0;

    int weekly_limit = 350;

    for (int i = 0; i < 7; i++)
    {
        user_value = get_value_from_user(week[i]);
        for (int j = 0; j < 3; j++)
        {
            week1_values[i][j] = user_value[j];
        }
    }

    printf("---------------------------- \n");
    printf("Enter value for Week 2 \n");

    for (int i = 0; i < 7; i++)
    {
        user_value = get_value_from_user(week[i]);
        for (int j = 0; j < 3; j++)
        {
            week2_values[i][j] = user_value[j];
        }
    }

    for (int i = 0; i < 7; i++)
    {
        int sum_day = 0;
        for (int j = 0; j < 3; j++)
        {
            sum_day = sum_day + week1_values[i][j];
        }
        printf("1. week %d. day avr: %d \n", i + 1, sum_day / 3);
        sum_daily1[i] = sum_day;
        sum_week1 = sum_week1 + sum_day;
    }

    for (int i = 0; i < 7; i++)
    {
        int sum_day = 0;
        for (int j = 0; j < 3; j++)
        {
            sum_day = sum_day + week2_values[i][j];
        }
        printf("2. week %d. day avr: %d \n", i, sum_day / 3);
        sum_daily2[i] = sum_day;
        sum_week2 = sum_week2 + sum_day;
    }

    avr_weekly1 = sum_week1 / 7;
    avr_weekly2 = sum_week2 / 7;

    if (avr_weekly1 == weekly_limit)
    {
        printf("You're right at the limit for week 1 \n");
    }
    else if (avr_weekly1 > weekly_limit)
    {
        printf("You're above at the limit for week 1 \n");
    }
    else
    {
        printf("Congratulations, you're below your limit for week 1 \n");
    }

    if (avr_weekly2 == weekly_limit)
    {
        printf("You're right at the limit for week 2 \n");
    }
    else if (avr_weekly2 > weekly_limit)
    {
        printf("You're above at the limit for week 2 \n");
    }
    else
    {
        printf("Congratulations, you're below your limit for week 2 \n");
    }

    if (avr_weekly1 == avr_weekly2)
    {
        printf("Your screen time in minutes is the same for both weeks for all categories. \n");
    }
    else if (avr_weekly1 > avr_weekly2)
    {
        printf("Great news! You've reduced your weekly screen time by %d minutes for all categories.", sum_week1 - sum_week2);
    }
    else
    {
        printf("I'm sorry, your screen usage has increased by %d minutes for all categories.", sum_week2 - sum_week1);
    }

    return 0;
}
