#include<stdio.h>

int main(void)
{
    int flag[100000];
    int N, sum, num;
    int max;
    int i, j;

    scanf("%d", &N);
    max = 0;
    sum = 0;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if(num > max)
        {
            flag[sum] = num;
            sum++;
            max = num;
        }
        else
        {
            for(j = sum - 1; j >= 0; j--)
                if(flag[j] > num)
                    sum--;
                else
                    break;
        }
    }
    printf("%d\n", sum);
    if(sum)
    {
        printf("%d", flag[0]);
        for(i = 1; i < sum; i++)
            printf(" %d", flag[i]);
    }
    putchar('\n');

    return 0;
}
