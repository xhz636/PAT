#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M, S, D;
int Length[500][500];
int Time[500][500];
int MinL = 0x7FFFFFFF, MinLT = 0x7FFFFFFF;
int MinT = 0x7FFFFFFF, MinTP = 0x7FFFFFFF;
int L[500], T[500];
int Lv[500], Tv[500];
int DijkL()
{
    for (int i = 0; i < N; i++)
    {
        L[i] = Length[S][i];
        if (!L[i])
            L[i] = 0x7FFFFFFF;
    }
    Lv[S] = 1;
    while (1)
    {
        int min = 0x7FFFFFFF, index;
        for (int i = 0; i < N; i++)
        {
            if (L[i] < min && !Lv[i])
            {
                min = L[i];
                index = i;
            }
        }
        Lv[index] = 1;
        if (index == D)
            return min;
        for (int i = 0; i < N; i++)
        {
            if (!Lv[i] && Length[index][i]
                    && L[index] + Length[index][i] < L[i])
                L[i] = L[index] + Length[index][i];
        }
    }
}
int DijkT()
{
    for (int i = 0; i < N; i++)
    {
        T[i] = Time[S][i];
        if (!T[i])
            T[i] = 0x7FFFFFFF;
    }
    Tv[S] = 1;
    while (1)
    {
        int min = 0x7FFFFFFF, index;
        for (int i = 0; i < N; i++)
        {
            if (T[i] < min && !Tv[i])
            {
                min = T[i];
                index = i;
            }
        }
        Tv[index] = 1;
        if (index == D)
            return min;
        for (int i = 0; i < N; i++)
        {
            if (!Tv[i] && Time[index][i]
                    && T[index] + Time[index][i] < T[i])
                T[i] = T[index] + Time[index][i];
        }
    }
}
int visit[500];
int NowL, NowT, NowP;
vector<int> LPath, TPath, NPath;
int DFS(int v)
{
    visit[v] = 1;
    NPath.push_back(v);
    if (v == D)
    {
        if (NowL < MinL || NowL == MinL && NowT < MinLT)
        {
            MinL = NowL;
            MinLT = NowT;
            LPath = NPath;
        }
        if (NowT < MinT || NowT == MinT && NowP < MinTP)
        {
            MinT = NowT;
            MinTP = NowP;
            TPath = NPath;
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!Length[v][i] || visit[i])
                continue;
            NowL += Length[v][i];
            NowT += Time[v][i];
            NowP++;
            if (NowL <= MinL || NowT <= MinT)
                DFS(i);
            NowL -= Length[v][i];
            NowT -= Time[v][i];
            NowP--;
        }
    }
    visit[v] = 0;
    NPath.pop_back();
}
int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int V1, V2, oneway, length, time;
        scanf("%d %d %d %d %d", &V1, &V2, &oneway, &length, &time);
        Length[V1][V2] = length;
        Time[V1][V2] = time;
        if (!oneway)
        {
            Length[V2][V1] = length;
            Time[V2][V1] = time;
        }
    }
    cin >> S >> D;
    MinL = DijkL();
    MinT = DijkT();
    DFS(S);
    if (LPath == TPath)
    {
        printf("Distance = %d; Time = %d: %d", MinL, MinT, S);
        for (int i = 1; i < LPath.size(); i++)
            printf(" -> %d", LPath[i]);
        putchar('\n');
    }
    else
    {
        printf("Distance = %d: %d", MinL, S);
        for (int i = 1; i < LPath.size(); i++)
            printf(" -> %d", LPath[i]);
        putchar('\n');
        printf("Time = %d: %d", MinT, S);
        for (int i = 1; i < TPath.size(); i++)
            printf(" -> %d", TPath[i]);
        putchar('\n');
    }
    return 0;
}
