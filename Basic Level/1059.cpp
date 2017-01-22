#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
int isprime(int i)
{
    if (i <= 1)
        return 0;
    else if (i == 2)
        return 1;
    else
    {
        for (int n = 2; n <= i / 2; n++)
            if (i % n == 0)
                return 0;
        return 1;
    }
}
int main(void)
{
    int N, K;
    map<int, int> rmap;
    cin >> N;
    int check[10001];
    for (int i = 1; i <= N; i++)
    {
        int id;
        check[id] = 0;
        cin >> id;
        rmap[id] = i;
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int id;
        cin >> id;
        if (rmap.count(id) == 0)
        {
            printf("%04d: Are you kidding?\n", id);
        }
        else if (!check[id])
        {
            int rank = rmap[id];
            if (rank == 1)
            {
                printf("%04d: Mystery Award\n", id);
            }
            else if (isprime(rank))
            {
                printf("%04d: Minion\n", id);
            }
            else
            {
                printf("%04d: Chocolate\n", id);
            }
            check[id] = 1;
        }
        else
        {
            printf("%04d: Checked\n", id);
        }
    }
    return 0;
}
