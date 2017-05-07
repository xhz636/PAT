#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int minprime(int n)
{
    while (1)
    {
        int isprime = 1;
        if (n < 2)
            n = 2;
        if (n == 2 || n == 3)
            break;
        else
        {
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                {
                    isprime = 0;
                    break;
                }
            if (isprime)
                break;
            else
                n++;
        }
    }
    return n;
}
int Table[10000];
int MSize;
int insert(int num)
{
    int pos = num % MSize;
    pos++;
    for (int i = 0; i <= MSize; i++)
    {
        pos = pos + i + i - 1;
        pos %= MSize;
        if (Table[pos] == 0)
        {
            Table[pos] = 1;
            return pos;
        }
    }
    return -1;
}
int first = 1;
int main(void)
{
    int N;
    cin >> MSize >> N;
    MSize = minprime(MSize);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        int pos = insert(num);
        if (first)
            first = 0;
        else
            putchar(' ');
        if (pos == -1)
            putchar('-');
        else
            printf("%d", pos);
    }
    putchar('\n');
    return 0;
}
