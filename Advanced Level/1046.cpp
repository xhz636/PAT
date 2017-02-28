#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int D[N + 1];
    D[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &D[i]);
        D[i] += D[i - 1];
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int min = a < b ? a : b;
        int max = a < b ? b : a;
        int dist = D[max - 1] - D[min - 1];
        if (dist < D[N] - dist)
            printf("%d\n", dist);
        else
            printf("%d\n", D[N] - dist);
    }
    return 0;
}
