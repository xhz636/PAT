#include<stdio.h>
#include<stdlib.h>

void find(int city[][1001], int *mark, int N, int step, int care);

int main(void)
{
    int N, M, K;
    int (*city)[1001];
    int citys, cityd, care;
    int count;
    int mark[1001];
    int i, j;

    city = (int (*) [1001])malloc(sizeof(int) * 1001 * 1001);
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            city[i][j] = 0;
    for(i = 0; i < M; i++)
    {
        scanf("%d %d", &citys, &cityd);
        city[citys][cityd] = 1;
        city[cityd][citys] = 1;
    }
    for(i = 0; i < K; i++)
    {
        scanf("%d", &care);
        count = 0;
        for(j = 1; j <= N; j++)
            mark[j] = 0;
        mark[care] = 1;
        for(j = 1; j <= N; j++)
        {
            if(!mark[j])
            {
                find(city, mark, N, j, care);
                count++;
            }
        }
        printf("%d\n", count - 1);
    }

    return 0;
}

void find(int city[][1001], int *mark, int N, int step, int care)
{
    int i;

    mark[step] = 1;
    for(i = 1; i <= N; i++)
        if(city[step][i] && !mark[i] && i != care)
            find(city, mark, N, i, care);

    return;
}
