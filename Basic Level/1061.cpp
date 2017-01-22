#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    int S[100], Q[100];
    for (int i = 0; i < M; i++)
        cin >> S[i];
    for (int i = 0; i < M; i++)
        cin >> Q[i];
    for (int i = 0; i < N; i++)
    {
        int score = 0;
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a == Q[j])
                score += S[j];
        }
        cout << score << endl;
    }
    return 0;
}
