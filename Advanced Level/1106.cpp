#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double P, r;
int C[100000];
double price[100000];

void sell(int index)
{
    if (price[C[index]] < 0)
        sell(C[index]);
    price[index] = price[C[index]] * r;
}

int main(void)
{
    int N;
    cin >> N >> P >> r;
    r = (r / 100) + 1;
    int retailer[N];
    for (int i = 0; i < N; i++)
    {
        int count;
        cin >> count;
        if (count == 0)
            retailer[i] = 1;
        else
        {
            retailer[i] = 0;
            for (int j = 0; j < count; j++)
            {
                int index;
                cin >> index;
                C[index] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
        price[i] = -1;
    price[0] = P;
    for (int i = 1; i < N; i++)
    {
        if (price[i] < 0)
            sell(i);
    }
    double min = 2e10;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (retailer[i])
        {
            if (price[i] < min)
            {
                min = price[i];
                count = 1;
            }
            else if (price[i] == min)
                count++;
        }
    }
    printf("%.4f %d\n", min, count);
    return 0;
}
