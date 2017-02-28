#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int N;
    cin >> N;
    int m, n, tm = N, tn = 1;
    while (tm >= tn)
    {
        if (tm * tn == N)
        {
            m = tm;
            n = tn;
        }
        tn++;
        tm = N / tn;
    }
    int S[N];
    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(S, S + N, cmp);
    int M[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = -1;
    int dir = 0;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        M[y][x] = S[i];
        switch (dir)
        {
            case 0: x++; break;
            case 1: y++; break;
            case 2: x--; break;
            case 3: y--; break;
        }
        if (x < 0 || x >= n || y < 0 || y >= m
                || M[y][x] != -1)
        {
            dir = (dir + 1) % 4;
            switch (dir)
            {
                case 0: y++; x++; break;
                case 1: x--; y++; break;
                case 2: y--; x--; break;
                case 3: x++; y--; break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << M[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << M[i][j];
        cout << endl;
    }
    return 0;
}
