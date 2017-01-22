#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N1, M1, N2, M2, K;
    int F[1000], FC = 0;
    scanf("%d/%d", &N1, &M1);
    scanf("%d/%d", &N2, &M2);
    scanf("%d", &K);
    for (int i = 2; i <= K / 2; i++)
        if (K % i == 0)
            F[FC++] = i;
    F[FC++] = K;
    double D1, D2;
    D1 = (double)N1 / M1;
    D2 = (double)N2 / M2;
    if (D1 > D2)
    {
        double T;
        T = D2;
        D2 = D1;
        D1 = T;
    }
    int first = 1;
    int N = (int)(D1 * K) + 1;
    while ((double)N / K < D2)
    {
        int flag = 1;
        for (int i = 0; i < FC; i++)
            if (N % F[i] == 0)
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            if (first)
            {
                first = 0;
                printf("%d/%d", N, K);
            }
            else
            {
                printf(" %d/%d", N, K);
            }
        }
        N++;
    }
    putchar('\n');
    return 0;
}
