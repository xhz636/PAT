#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int edge[201][201];

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        edge[v1][v2] = edge[v2][v1] = 1;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        int pv, nv;
        cin >> pv;
        int start = pv;
        int ham = 1;
        if (n != N + 1)
            ham = 0;
        int visit[N + 1];
        if (ham)
        {
            for (int j = 1; j <= N; j++)
                visit[j] = 0;
        }
        for (int j = 1; j < n; j++)
        {
            cin >> nv;
            if (ham)
            {
                if (!edge[pv][nv])
                    ham = 0;
                if (j == n - 1)
                {
                    if (nv != start)
                        ham = 0;
                }
                if (visit[nv])
                    ham = 0;
                else
                    visit[nv] = 1;
                pv = nv;
            }
        }
        if (ham)
        {
            for (int j = 1; j <= N; j++)
                if (!visit[j])
                {
                    ham = 0;
                    break;
                }
        }
        if (ham)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
