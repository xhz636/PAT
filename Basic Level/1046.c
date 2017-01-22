#include<stdio.h>

int main(void)
{
    int count[2];
    int N, i;
    int jia[2], yi[2];

    scanf("%d", &N);
    count[0] = count[1] = 0;
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &jia[0], &jia[1], &yi[0], &yi[1]);
        if(jia[1] == jia[0] + yi[0] && yi[1] != jia[1])
            count[1]++;
        else if(yi[1] == jia[0] + yi[0] && yi[1] != jia[1])
            count[0]++;
    }
    printf("%d %d\n", count[0], count[1]);

    return 0;
}
