#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
    int ID;
    int GE;
    int GI;
    vector<int> order;
} App;
bool cmp(App a, App b)
{
    if (a.GE + a.GI != b.GE + b.GI)
        return a.GE + a.GI > b.GE + b.GI;
    else
        return a.GE > b.GE;
}
int main(void)
{
    int N, M, K;
    cin >> N >> M >> K;
    int Quota[M];
    int Rank[M];
    vector<int> School[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &Quota[i]);
        Rank[i] = 0;
    }
    App A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i].GE, &A[i].GI);
        A[i].ID = i;
        for (int j = 0; j < K; j++)
        {
            int num;
            scanf("%d", &num);
            A[i].order.push_back(num);
        }
    }
    sort(A, A + N, cmp);
    int nowrank = 0;
    int laste = A[0].GE, lasti = A[0].GI;
    for (int i = 0; i < N; i++)
    {
        if (A[i].GE + A[i].GI != laste + lasti || A[i].GE != laste)
        {
            nowrank++;
            laste = A[i].GE;
            lasti = A[i].GI;
        }
        for (int j = 0; j < K; j++)
        {
            int want = A[i].order[j];
            if (Rank[want] == nowrank
                    || School[want].size() < Quota[want])
            {
                School[want].push_back(A[i].ID);
                Rank[want] = nowrank;
                break;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        sort(School[i].begin(), School[i].end());
        for (int j = 0; j < School[i].size(); j++)
        {
            if (j != 0)
                putchar(' ');
            printf("%d", School[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
