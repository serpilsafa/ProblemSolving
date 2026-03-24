#include <stdio.h>
#include <stdlib.h>

int main()
{
    int category_count;

    char week[7][10] = {"Monday", "Tuesday", "Wendesday", "Thuersday", "Friday", "Saturday", "Sunday"};

    int week1_values[7][3];
    int week2_values[7][3];

    int sum_daily1[7];
    int sum_week1 = 0;
    int avr_weekly1 = 0;

    int sum_daily2[7];
    int sum_week2 = 0;
    int avr_weekly2 = 0;

    int weekly_limit = 350;

    printf("How many categories do want to enter? : \n");
    scanf("%d", &category_count);
    char **categories = (char **)malloc(category_count * sizeof(char *));

    if (categories == NULL)
    {
        printf("Error: Memory allocation! \n");
        return 1;
    }

    for (int i = 0; i < category_count; i++)
    {
        categories[i] = (char *)malloc(50 * sizeof(char)); // max 50 character

        if (categories[i] == NULL)
        {
            printf("Error: Memory allocation!\n");
            return 1;
        }
    }

    for (int i = 0; i < category_count; i++)
    {
        printf("%d. enter category name : ", i + 1);
        scanf("%s", categories[i]);
    }

    printf("\nYou enter these categories:\n");
    for (int i = 0; i < category_count; i++)
    {
        printf("%d - %s\n", i + 1, categories[i]);
    }

    printf("---------------------------- \n");
    printf("Enter value for Week 1 \n");
    for (int i = 0; i < 7; i++)
    {

        int *value = malloc(category_count * sizeof(int));
        for (int j = 0; j < category_count; j++)
        {
            printf("Enter the number of minutes you used for %s applications for 1.week %s : \n", categories[j], week[i]);
            scanf("%d", &value[j]);
            if (value[j] < 0)
            {
                printf("Invalid number");
                return 0;
            }
            week1_values[i][j] = value[j];
        }

        free(value);
    }

    printf("---------------------------- \n");
    printf("Enter value for Week 2 \n");
    for (int i = 0; i < 7; i++)
    {

        int *value = malloc(category_count * sizeof(int));
        for (int j = 0; j < category_count; j++)
        {
            printf("Enter the number of minutes you used for %s applications for 2.week  %s : \n", categories[j], week[i]);
            scanf("%d", &value[j]);
            if (value[j] < 0)
            {
                printf("Invalid number");
                return 0;
            }
            week2_values[i][j] = value[j];
        }

        free(value);
    }

    for (int i = 0; i < 7; i++)
    {
        int sum_day = 0;
        for (int j = 0; j < category_count; j++)
        {
            sum_day = sum_day + week1_values[i][j];
        }
        printf("1. week %s avr: %d \n", week[i], sum_day / category_count);
        sum_daily1[i] = sum_day;
        sum_week1 = sum_week1 + sum_day;
    }

    for (int i = 0; i < 7; i++)
    {
        int sum_day = 0;
        for (int j = 0; j < category_count; j++)
        {
            sum_day = sum_day + week2_values[i][j];
        }
        printf("2. week %s avr: %d \n", week[i], sum_day / category_count);
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

    // Memory free
    for (int i = 0; i < category_count; i++)
    {
        free(categories[i]);
    }
    free(categories);

    return 0;
}
