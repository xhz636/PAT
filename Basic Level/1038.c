#include<stdio.h>

int main(void)
{
    int n, k, i, index;
    int score[100001] = {0};

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &index);
        score[index]++;
    }
    scanf("%d", &k);
    scanf("%d", &index);
    printf("%d", score[index]);
    for(i = 1; i < k; i++)
    {
        scanf("%d", &index);
        printf(" %d", score[index]);
    }
    putchar('\n');

    return 0;
}
