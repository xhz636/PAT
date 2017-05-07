#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Solution;
int Coin[10000];
int cnt;
int find(int begin, int sum)
{
    if (sum > (cnt - begin) * Coin[cnt - 1])
        return 0;
    for (int i = begin; i < cnt && Coin[i] <= sum; i++)
    {
        sum -= Coin[i];
        Solution.push_back(Coin[i]);
        if (sum == 0 || find(i + 1, sum))
            return 1;
        else
        {
            sum += Coin[i];
            Solution.pop_back();
        }
    }
    return 0;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        if (num <= M)
            Coin[cnt++] = num;
    }
    sort(Coin, Coin + cnt);
    if (find(0, M))
    {
        for (int i = 0; i < Solution.size(); i++)
        {
            if (i != 0)
                putchar(' ');
            printf("%d", Solution[i]);
        }
        putchar('\n');
    }
    else
        printf("No Solution\n");
    return 0;
}
