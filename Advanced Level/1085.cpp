#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    long long int N, p;
    cin >> N >> p;
    long long int num[N];
    for (int i = 0; i < N; i++)
        scanf("%lld", &num[i]);
    sort(num, num + N);
    int M = 0, m = 0;
    int max = 0;
    for (m = 0; m < N; m++)
    {
        while (num[M] <= num[m] * p)
        {
            M++;
            if (M == N)
                break;
        }
        if (max < M - m)
            max = M - m;
        if (M == N)
            break;
    }
    cout << max << endl;
    return 0;
}
