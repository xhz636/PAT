#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> List[1001];
int Visit[1001];
int forward(vector<int> order, int level)
{
    if (!level)
        return 0;
    else
    {
        int amount = 0;
        vector<int> next;
        for (int i = 0; i < order.size(); i++)
        {
            if (!Visit[order[i]])
            {
                Visit[order[i]] = 1;
                amount++;
                for (int j = 0; j < List[order[i]].size(); j++)
                    if (!Visit[List[order[i]][j]])
                        next.push_back(List[order[i]][j]);
            }
        }
        amount += forward(next, level - 1);
        return amount;
    }
}
int main(void)
{
    int N, L;
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            int ID;
            scanf("%d", &ID);
            List[ID].push_back(i);
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int Q;
        scanf("%d", &Q);
        for (int i = 1; i <= N; i++)
            Visit[i] = 0;
        Visit[Q] = 1;
        printf("%d\n", forward(List[Q], L));
    }
    return 0;
}
