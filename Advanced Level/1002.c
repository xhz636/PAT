#include<stdio.h>
#include<stdlib.h>

struct pol
{
    int exp;
    double coe;
} num[20];

int cmp(struct pol *a, struct pol *b)
{
    return b->exp - a->exp;
}

int main(void)
{
    int k, n, i, j, count, sum;
    int expt;
    double coet;

    count = 0;
    for(n = 0; n < 2; n++)
    {
        scanf("%d", &k);
        for(i = 0; i < k; i++)
        {
            scanf("%d %lf", &expt, &coet);
            for(j = 0; j < count; j++)
            {
                if(num[j].exp == expt)
                {
                    num[j].coe += coet;
                    break;
                }
            }
            if(j == count)
            {
                num[count].exp = expt;
                num[count].coe = coet;
                count++;
            }
        }
    }
    qsort(num, count, sizeof(struct pol), cmp);
    for(i = 0, sum = 0; i < count; i++)
        if(num[i].coe != 0)
            sum++;
    printf("%d", sum);
    for(i = 0; i < count; i++)
        if(num[i].coe != 0)
            printf(" %d %.1f", num[i].exp, num[i].coe);
    putchar('\n');

    return 0;
}
