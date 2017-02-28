#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int num[N];
    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    int S1 = 0, S2 = 0;
    for (int i = 0; i < N / 2; i++)
        S1 += num[i];
    for (int i = N / 2; i < N; i++)
        S2 += num[i];
    cout << N % 2 << " " << S2 - S1 << endl;
    return 0;
}
