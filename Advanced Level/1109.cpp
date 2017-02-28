#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct
{
    char name[10];
    int height;
} P;
bool cmp(P a, P b)
{
    if (a.height != b.height)
        return a.height > b.height;
    else
        return strcmp(a.name, b.name) < 0;
}
int main(void)
{
    int N, K;
    P* people;
    scanf("%d %d", &N, &K);
    people = (P*)malloc(sizeof(P) * N);
    for (int i = 0; i < N; i++)
        scanf("%s %d", people[i].name, &people[i].height);
    sort(people, people + N, cmp);
    int offset = 0;
    for (int i = 0; i < K; i++)
    {
        int count;
        if (i == 0)
            count = N - N / K * (K - 1);
        else
            count = N / K;
        int j;
        for (j = 0; j < count / 2; j++)
            printf("%s ", people[offset + (count / 2 - j) * 2 - 1].name);
        for (; j < count; j++)
        {
            if (j != count - 1)
                printf("%s ", people[offset + (j - count / 2) * 2].name);
            else
                printf("%s\n", people[offset + (j - count / 2) * 2].name);
        }
        offset += count;
    }
    return 0;
}
