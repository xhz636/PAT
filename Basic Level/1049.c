#include<stdio.h>

int main(void)
{
    int N, i, times;
    double sum;
    double num;

    scanf("%d", &N);
    sum = 0;
    times = 1;
    for(i = 0; i < N; i++)
    {
        scanf("%lf", &num);
        sum += num * (N - i) * times++;
    }
    printf("%.2f\n", sum);

    return 0;
}
