#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> Chain[100000];
double price[100000], r;
double amount[100000];
vector<int> retailer;
void cal(int index, double p)
{
    price[index] = p;
    for (int i = 0; i < Chain[index].size(); i++)
        cal(Chain[index][i], p * r);
}
int main(void)
{
    int N;
    cin >> N >> price[0] >> r;
    r = 1.0 + r / 100;
    for (int i = 0; i < N; i++)
    {
        int K;
        scanf("%d", &K);
        if (K != 0)
        {
            for (int j = 0; j < K; j++)
            {
                int next;
                scanf("%d", &next);
                Chain[i].push_back(next);
            }
        }
        else
        {
            retailer.push_back(i);
            scanf("%lf", &amount[i]);
        }
    }
    cal(0, price[0]);
    double total = 0;
    for (int i = 0; i < retailer.size(); i++)
        total += price[retailer[i]] * amount[retailer[i]];
    printf("%.1f\n", total);
    return 0;
}
