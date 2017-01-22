#include<stdio.h>

int main(void)
{
    int N;
    int i, j;
    int sum_score;
    int max_score, champion;
    int score[1001][11];
    int team, member;

    for(i = 1; i <= 1000; i++)
        for(j = 1; j <= 10; j++)
            score[i][j] = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d%*c%d", &team, &member);
        scanf("%d", &score[team][member]);
    }
    max_score = 0;
    for(i = 1; i <= 1000; i++)
    {
        sum_score = 0;
        for(j = 1; j <= 10; j++)
            sum_score += score[i][j];
        if(sum_score > max_score)
        {
            max_score = sum_score;
            champion = i;
        }
    }
    printf("%d %d\n", champion, max_score);

    return 0;
}
