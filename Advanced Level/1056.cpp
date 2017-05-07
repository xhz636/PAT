#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int main(void)
{
    int NP, NG;
    cin >> NP >> NG;
    int mice[NP];
    for (int i = 0; i < NP; i++)
        scanf("%d", &mice[i]);
    queue<int> order, next;
    for (int i = 0; i < NP; i++)
    {
        int temp;
        scanf("%d", &temp);
        order.push(temp);
    }
    int Rank[NP];
    int count = order.size();
    while (order.size())
    {
        int max;
        int loser = count / NG + (count % NG != 0) + 1;
        for (int i = 0; i < NG && order.size(); i++)
        {
            Rank[order.front()] = loser;
            if (i == 0)
                max = order.front();
            else if (mice[order.front()] > mice[max])
                max = order.front();
            order.pop();
        }
        next.push(max);
        if (order.size() == 0)
        {
            order = next;
            count = order.size();
            while (next.size())
                next.pop();
            if (order.size() == 1)
                break;
        }
    }
    Rank[order.front()] = 1;
    int first = 1;
    for (int i = 0; i < NP; i++)
    {
        if (first)
            printf("%d", Rank[i]);
        else
            printf(" %d", Rank[i]);
        first = 0;
    }
    putchar('\n');
    return 0;
}
