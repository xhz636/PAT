#include<stdio.h>
#include<stdlib.h>

struct polynomial
{
    int exponent;
    double coefficient;
} a[10], b[10], c[100];

int cmp(const void* a, const void* b)
{
    return ((struct polynomial*)b)->exponent - ((struct polynomial*)a)->exponent;
}

int main(void)
{
    int k1, k2, i, j, p, num = 0;
    int exp;
    double coe;

    scanf("%d", &k1);
    for(i = 0; i < k1; i++)
        scanf("%d %lf", &a[i].exponent, &a[i].coefficient);
    scanf("%d", &k2);
    for(i = 0; i < k2; i++)
        scanf("%d %lf", &b[i].exponent, &b[i].coefficient);
    for(i = 0; i < k1; i++)
        for(j = 0; j < k2; j++)
        {
            exp = a[i].exponent + b[j].exponent;
            coe = a[i].coefficient * b[j].coefficient;
            for(p = 0; c[p].coefficient != 0 && c[p].exponent != exp; p++)
                continue;
            c[p].exponent = exp;
            c[p].coefficient += coe;
            if(p > num)
                num = p;
        }
    num++;
    qsort(c, num, sizeof(struct polynomial), cmp);
    printf("%d", num);
    for(i = 0; i < num; i++)
        printf(" %d %.1f", c[i].exponent, c[i].coefficient);
    putchar('\n');

    return 0;
}
