#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, D[100000], E = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> D[i];
    sort(D, D + N);
    for (int i = 0; i < N; i++)
        if (D[N - 1 - i] > i + 1)
            E = i + 1;
        else
            break;
    cout << E << endl;
    return 0;
}
