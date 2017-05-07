#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
    int id;
    int total;
    int Count;
    int S[6];
} User;
bool cmp(User a, User b)
{
    if (a.total != b.total)
        return a.total > b.total;
    else if (a.Count != b.Count)
        return a.Count > b.Count;
    else
        return a.id < b.id;
}
int main(void)
{
    int N, K, M;
    cin >> N >> K >> M;
    int P[6];
    User U[N + 1];
    for (int i = 1; i <= K; i++)
        cin >> P[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
        {
            U[i].id = i;
            U[i].total = -1;
            U[i].Count = 0;
            U[i].S[j] = -2;
        }
    for (int i = 0; i < M; i++)
    {
        int id, num, score;
        scanf("%d %d %d", &id, &num, &score);
        if (score == -1)
        {
            if (U[id].S[num] == -2)
                U[id].S[num] = -1;
        }
        else if (U[id].S[num] < 0)
        {
            if (score == P[num])
                U[id].Count++;
            U[id].S[num] = score;
            if (U[id].total == -1)
                U[id].total = 0;
            U[id].total += score;
        }
        else if (U[id].S[num] < score)
        {
            if (score == P[num])
                U[id].Count++;
            U[id].total += score - U[id].S[num];
            U[id].S[num] = score;
        }
    }
    sort(U + 1, U + N + 1, cmp);
    int rank = 0;
    int count = 1;
    int total = -1;
    for (int i = 1; i <= N; i++)
    {
        if (U[i].total == -1)
            break;
        if (total != U[i].total)
        {
            total = U[i].total;
            rank += count;
            count = 1;
        }
        else
            count++;
        printf("%d %05d %d", rank, U[i].id, U[i].total);
        for (int j = 1; j <= K; j++)
            if (U[i].S[j] == -2)
                printf(" -");
            else if (U[i].S[j] == -1)
                printf(" 0");
            else
                printf(" %d", U[i].S[j]);
        putchar('\n');
    }
    return 0;
}
