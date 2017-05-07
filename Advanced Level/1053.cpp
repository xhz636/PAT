#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int Weight[100];
int NonLeaf[100];
vector<int> Children[100];
int N, M, S;
int Sum;
vector<int> Path;
void show()
{
    for (int i = 0; i < Path.size(); i++)
        if (i == 0)
            printf("%d", Path[i]);
        else
            printf(" %d", Path[i]);
    putchar('\n');
}
void find(int index)
{
    Sum += Weight[index];
    Path.push_back(Weight[index]);
    if (Sum == S && !NonLeaf[index])
    {
        show();
    }
    else if (Sum < S && NonLeaf[index])
    {
        for (int i = 0; i < Children[index].size(); i++)
            find(Children[index][i]);
    }
    Sum -= Weight[index];
    Path.pop_back();
}
bool cmp(int a, int b)
{
    return Weight[a] > Weight[b];
}
int main(void)
{
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++)
        scanf("%d", &Weight[i]);
    for (int i = 0; i < M; i++)
    {
        int ID, K;
        scanf("%d %d", &ID, &K);
        NonLeaf[ID] = 1;
        for (int j = 0; j < K; j++)
        {
            int child;
            scanf("%d", &child);
            Children[ID].push_back(child);
        }
        sort(Children[ID].begin(), Children[ID].end(), cmp);
    }
    find(0);
    return 0;
}
