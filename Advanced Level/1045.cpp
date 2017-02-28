#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, M, L;
    cin >> N;
    cin >> M;
    int F[M];
    for (int i = 0; i < M; i++)
        cin >> F[i];
    cin >> L;
    int S[L];
    for (int i = 0; i < L; i++)
        cin >> S[i];
    int Now[M];
    for (int i = 0; i < M; i++)
        Now[i] = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j > 0)
                Now[j] = Now[j] > Now[j - 1] ? Now[j] : Now[j - 1];
            if (S[i] == F[j])
                Now[j]++;
        }
    }
    cout << Now[M - 1] << endl;
    return 0;
}
