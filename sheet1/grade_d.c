#include <stdio.h>

int main()
{

    int social, video, games, daily_scroll_threshold;
    social = 100;
    video = 70;
    games = 20;

    daily_scroll_threshold = social + video + games;
    printf("Your total weekly screen time: %d \n", daily_scroll_threshold);

    if (daily_scroll_threshold > 180)
    {

        printf("Daily scroll threshold exceeded \n");
    }

    return 0;
}
