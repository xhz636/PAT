#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void simply(long long int& num, long long int& den)
{
    for (int i = 2; i <= den; i++)
    {
        if (num % i == 0 && den % i == 0)
        {
            num /= i;
            den /= i;
            i--;
        }
    }
}

int main(void)
{
    int N;
    long long int num, den;
    long long int up, down;
    cin >> N;
    scanf("%lld/%lld", &up, &down);
    for (int i = 1; i < N; i++)
    {
        scanf("%lld/%lld", &num, &den);
        up = up * den + num * down;
        down = down * den;
        simply(up, down);
    }
    if (up == 0)
    {
        printf("0\n");
        return 0;
    }
    if (up < 0)
    {
        putchar('-');
        up = -up;
    }
    if (up >= down)
    {
        printf("%lld", up / down);
        if (up % down)
            putchar(' ');
    }
    if (up % down != 0)
        printf("%lld/%lld", up % down, down);
    putchar('\n');
    return 0;
}
