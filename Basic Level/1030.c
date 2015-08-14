#include<stdio.h>

int cmp(const double *a, const double *b)
{
    return *a - *b;
}

int main(void)
{
    int n, i, j, count;
    double p, num[100000];

    scanf("%d %lf", &n, &p);
    for(i = 0; i < n; i++)
        scanf("%lf", &num[i]);
    qsort(num, n, sizeof(double), cmp);
    count = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i + count; j < n; j++)
            if(num[j] <= num[i] * p)
                count = j - i + 1;
            else
                break;
    }
    printf("%d\n", count);

    return 0;
}
