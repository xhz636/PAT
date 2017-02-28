#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int ID[10001];
int M[10001];
int S[10001];
int A[10001];
int isRoot[10001];

int find(int index)
{
    if (ID[index] > 0)
        return find(ID[index]);
    else
        return index;
}

int merge(int index1, int index2)
{
    int root1 = find(index1);
    int root2 = find(index2);
    isRoot[root1] = 1;
    isRoot[root2] = 1;
    if (root1 == root2)
        return root1;
    if (root1 < root2)
    {
        ID[root2] = root1;
        isRoot[root2] = 0;
        M[root1] += M[root2];
        S[root1] += S[root2];
        A[root1] += A[root2];
        return root1;
    }
    else if (root1 > root2)
    {
        ID[root1] = root2;
        isRoot[root1] = 0;
        M[root2] += M[root1];
        S[root2] += S[root1];
        A[root2] += A[root1];
        return root2;
    }
}

typedef struct
{
    int id;
    int m;
    double avg_sets;
    double avg_area;
} Family;

bool cmp(Family a, Family b)
{
    if (a.avg_area != b.avg_area)
        return a.avg_area > b.avg_area;
    else
        return a.id < b.id;
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int id, father, mother, k;
        int member = 0, sets = 0, areas = 0;
        scanf("%d %d %d %d", &id, &father, &mother, &k);
        id++;
        if (M[id] == 0)
            M[id] = 1;
        merge(id, id);
        if (father != -1)
        {
            father++;
            if (M[father] == 0)
                M[father] = 1;
            merge(id, father);
        }
        if (mother != -1)
        {
            mother++;
            if (M[mother] == 0)
                M[mother] = 1;
            merge(id, mother);
        }
        for (int j = 0; j < k; j++)
        {
            int child;
            scanf("%d", &child);
            child++;
            if (M[child] == 0)
                M[child] = 1;
            merge(id, child);
        }
        int state, area;
        scanf("%d %d", &state, &area);
        int root = find(id);
        S[root] += state;
        A[root] += area;
    }
    Family F[N];
    int cnt = 0;
    for (int i = 0; i <= 10000; i++)
        if (isRoot[i])
        {
            F[cnt].id = i;
            F[cnt].m = M[i];
            F[cnt].avg_sets = (double)S[i] / (double)M[i];
            F[cnt].avg_area = (double)A[i] / (double)M[i];
            cnt++;
        }
    sort(F, F + cnt, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", F[i].id - 1, F[i].m, F[i].avg_sets, F[i].avg_area);
    return 0;
}
