#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int find(int num, int& max, int& min)
{
    int digit[10];
    for (int i = 0; i < 10; i++)
        digit[i] = 0;
    for (int i = 0; i < 4; i++)
    {
        digit[num % 10]++;
        num /= 10;
    }
    max = min = 0;
    int pow = 1;
    for (int i = 0; i < 10; i++)
    {
        while (digit[i])
        {
            min = min * 10 + i;
            max = max + pow * i;
            digit[i]--;
            pow *= 10;
        }
    }
}

int main(void)
{
    int N;
    cin >> N;
    int max, min;
    do {
        find(N, max, min);
        N = max - min;
        printf("%04d - %04d = %04d\n", max, min, N);
    } while (max != min && N != 6174);
    return 0;
}
