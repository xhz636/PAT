#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int nextprime(int n)
{
    if (n == 2)
        return 3;
    while (1)
    {
        n++;
        int i;
        for (i = 2; i <= n / 2; i++)
            if (n % i == 0)
                break;
        if (i > n / 2)
            return n;
    }
}

int main(void)
{
    int N;
    cin >> N;
    cout << N << "=";
    if (N <= 1)
    {
        cout << N << endl;
        return 0;
    }
    int F = 2, P = 0;
    while (N > 1)
    {
        if (N % F == 0)
        {
            N /= F;
            P++;
        }
        else
        {
            if (P == 1)
            {
                printf("%d*", F);
                P = 0;
            }
            else if (P > 1)
            {
                printf("%d^%d*", F, P);
                P = 0;
            }
            F = nextprime(F);
        }
    }
    if (P == 1)
    {
        printf("%d\n", F);
        P = 0;
    }
    else if (P > 1)
    {
        printf("%d^%d\n", F, P);
        P = 0;
    }
    return 0;
}
