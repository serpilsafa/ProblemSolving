#include <stdio.h>

int main()
{

    int social, video, game, daily_scroll_threshold, recommended_limit;
    recommended_limit = 40;

    printf("Enter the number of minutes you used for social applications: ");
    scanf("%d", &social);
    if (social < 0)
    {
        printf("Invalid number");
        return 0;
    }

    printf("Enter the number of minutes you used for video applications: ");
    scanf("%d", &video);
    if (video < 0)
    {
        printf("Invalid number");
        return 0;
    }

    printf("Enter the number of minutes you used for game applications: ");
    scanf("%d", &game);
    if (game < 0)
    {
        printf("Invalid number");
        return 0;
    }

    daily_scroll_threshold = social + video + game;

    if (daily_scroll_threshold > recommended_limit)
    {
        printf("Above recommended limit");
    }
    else
    {
        printf("Within recommended limit");
    }

    return 0;
}
