#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> node[100];
int level[100], cnt[100];
int maxlevel;
void cal(int index, int lv)
{
    if (lv > maxlevel)
        maxlevel = lv;
    level[index] = lv;
    for (int i = 0; i < node[index].size(); i++)
        cal(node[index][i], lv + 1);
}
int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int parent, K;
        scanf("%d %d", &parent, &K);
        for (int j = 0; j < K; j++)
        {
            int child;
            scanf("%d", &child);
            node[parent].push_back(child);
        }
    }
    cal(1, 1);
    for (int i = 1; i <= N; i++)
        cnt[level[i]]++;
    int max = 0, index;
    for (int i = 1; i <= maxlevel; i++)
        if (cnt[i] > max)
        {
            max = cnt[i];
            index = i;
        }
    cout << max << " " << index << endl;
    return 0;
}
