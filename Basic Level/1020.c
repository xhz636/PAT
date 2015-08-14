#include<stdio.h>

struct
{
    double amount;
    double price;
    double unit;
} goods[1000], t;

int main(void)
{
    int n, d, i, j;
    double income, out;

    scanf("%d %d", &n, &d);
    for(i = 0; i < n; i++)
        scanf("%lf", &goods[i].amount);
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &goods[i].price);
        goods[i].unit = goods[i].price / goods[i].amount;
    }
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(goods[j].unit < goods[j + 1].unit)
            {
                t = goods[j];
                goods[j] = goods[j + 1];
                goods[j + 1] = t;
            }
    for(i = 0, income = 0, out = 0; out < d && i < n; out += goods[i].amount, i++)
        if(goods[i].amount + out <= d)
            income += goods[i].price;
        else
            income += ((double)d - out) * goods[i].unit;
    printf("%.2f\n", income);

    return 0;
}
