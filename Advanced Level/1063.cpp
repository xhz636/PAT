#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    set<int> S[N + 1];
    for (int i = 1; i <= N; i++)
    {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            int num;
            scanf("%d", &num);
            S[i].insert(num);
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        double Nc = 0, Nt = S[num1].size();
        set<int>::iterator it;
        for (it = S[num2].begin(); it != S[num2].end(); it++)
            if (S[num1].find(*it) == S[num1].end())
                Nt++;
            else
                Nc++;
        printf("%.1f%%\n", Nc / Nt * 100);
    }
    return 0;
}
