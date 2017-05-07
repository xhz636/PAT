#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int notretailer[100000];
vector<int> chain[100000];
double price[100000];
double P, r;
int N;
void cal(int index, double p)
{
    price[index] = p;
    for (int i = 0; i < chain[index].size(); i++)
        cal(chain[index][i], p * r);
}
int main(void)
{
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int root;
    for (int i = 0; i < N; i++)
    {
        int index;
        scanf("%d", &index);
        if (index == -1)
            root = i;
        else
        {
            chain[index].push_back(i);
            notretailer[i] = 1;
        }
    }
    cal(root, P);
    double maxprice = 0;
    int maxcnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (price[i] > maxprice)
        {
            maxprice = price[i];
            maxcnt = 1;
        }
        else if (price[i] == maxprice)
            maxcnt++;
    }
    printf("%.2f %d\n", maxprice, maxcnt);
    return 0;
}
