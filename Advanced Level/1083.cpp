#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
    char name[12];
    char ID[12];
    int grade;
} Stu;
bool cmp(Stu a, Stu b)
{
    return a.grade > b.grade;
}
int main(void)
{
    int N;
    cin >> N;
    Stu S[N];
    for (int i = 0; i < N; i++)
        scanf("%s %s %d", S[i].name, S[i].ID, &S[i].grade);
    sort(S, S + N, cmp);
    int g1, g2;
    cin >> g1 >> g2;
    int exist = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i].grade >= g1 && S[i].grade <= g2)
        {
            printf("%s %s\n", S[i].name, S[i].ID);
            exist = 1;
        }
    }
    if (!exist)
        printf("NONE\n");
    return 0;
}
