#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int N, K, D;
    double e, E;
    cin >> N >> e >> D;
    int P1 = 0, P2 = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        int a = 0;
        for (int j = 0; j < K; j++)
        {
            cin >> E;
            if (E < e)
                a++;
        }
        if (a > K / 2.0)
        {
            if (K > D)
                P2++;
            else
                P1++;
        }
    }
    printf("%.1f%% %.1f%%\n", P1 * 100.0 / N, P2 * 100.0 / N);
    return 0;
}
