#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, M[10];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> M[i];
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += (M[i] * 11) * (N - 1);
    cout << sum << endl;
    return 0;
}
