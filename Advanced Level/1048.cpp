#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int coin[501];
int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        coin[v]++;
    }
    for (int i = 1; i <= 500 && i < M; i++)
    {
        if (M - i > 500)
            continue;
        if (M - i != i && coin[i] && coin[M - i])
        {
            cout << i << " " << M - i << endl;
            return 0;
        }
        else if (M - i == i && coin[i] > 1)
        {
            cout << i << " " << i << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
