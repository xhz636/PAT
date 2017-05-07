#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct
{
    char name[9];
    int age;
    int worth;
} People;

bool cmp(People a, People b)
{
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    People P[N];
    for (int i = 0; i < N; i++)
        scanf("%s %d %d", P[i].name, &P[i].age, &P[i].worth);
    sort(P, P + N, cmp);
    for (int i = 0; i < K; i++)
    {
        int cnt, min, max;
        scanf("%d %d %d", &cnt, &min, &max);
        printf("Case #%d:\n", i + 1);
        int count = cnt;
        for (int j = 0; j < N; j++)
        {
            if (P[j].age >= min && P[j].age <= max)
            {
                printf("%s %d %d\n", P[j].name, P[j].age, P[j].worth);
                count--;
                if (count == 0)
                    break;
            }
        }
        if (count == cnt)
            printf("None\n");
    }
    return 0;
}
