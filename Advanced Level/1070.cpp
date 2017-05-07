#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
    double amount;
    double price;
} MC;
bool cmp(MC a, MC b)
{
    return a.price / a.amount > b.price / b.amount;
}
int main(void)
{
    int N;
    double D;
    cin >> N >> D;
    MC Mooncake[N];
    for (int i = 0; i < N; i++)
        scanf("%lf", &Mooncake[i].amount);
    for (int i = 0; i < N; i++)
        scanf("%lf", &Mooncake[i].price);
    sort(Mooncake, Mooncake + N, cmp);
    double profit = 0;
    for (int i = 0; i < N && D > 0; i++)
    {
        if (D >= Mooncake[i].amount)
        {
            profit += Mooncake[i].price;
            D -= Mooncake[i].amount;
        }
        else
        {
            profit += Mooncake[i].price / Mooncake[i].amount * D;
            D = 0;
        }
    }
    printf("%.2f\n", profit);
    return 0;
}
