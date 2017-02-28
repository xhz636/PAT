#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int N, K, P;
int power[400];
int fact[400];
int factsum = 0;
int nowfact[400];
int index = 0;
int found = 0;

void find(int num, int cnt, int max)
{
    if (num == 0 && cnt == 0)
    {
        int sum = 0, big = 0;
        for (int i = 0; i < K; i++)
        {
            sum += nowfact[i];
            if (big == 0)
            {
                if (nowfact[i] > fact[i])
                    big = 1;
                else if (nowfact[i] < fact[i])
                    big = -1;
            }
        }
        if (sum > factsum ||
                sum == factsum && big == 1)
        {
            for (int i = 0; i < K; i++)
                fact[i] = nowfact[i];
            factsum = sum;
            found = 1;
        }
        return;
    }
    else if (cnt > 0 && num > 0 && num >= cnt)
    {
        for (int i = 1; i <= max; i++)
        {
            nowfact[index++] = i;
            find(num - power[i], cnt - 1, i);
            index--;
        }
    }
}

int intpow(int a, int b)
{
    int c = a;
    while (--b)
        c *= a;
    return c;
}

int main(void)
{
    cin >> N >> K >> P;
    int powcnt = 1;
    int pownum = 1;
    while(pownum <= N)
    {
        power[powcnt++] = pownum;
        pownum = intpow(powcnt, P);
    }
    find(N, K, powcnt - 1);
    if (!found)
        printf("Impossible\n");
    else
    {
        printf("%d = %d^%d", N, fact[0], P);
        for (int i = 1; i < K; i++)
            printf(" + %d^%d", fact[i], P);
        putchar('\n');
    }
    return 0;
}
