#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int nametoindex[26 * 26 * 26];
int indextoname[200];
int happy[200];
int cost[200][200];
int N, K, E;
int nameint(char* city)
{
    return (city[0] - 'A') * 26 * 26 +
        (city[1] - 'A') * 26 + city[2] - 'A';
}
vector<int> bestpath, nowpath;
int pathcnt;
int visit[200];
int mincost = 0x7FFFFFFF, nowcost, maxhappy, nowhappy;
void find(int index)
{
    if (visit[index])
        return;
    else if (nowcost > mincost)
        return;
    else
    {
        visit[index] = 1;
        nowpath.push_back(index);
        nowhappy += happy[index];
        if (index == E)
        {
            if (nowcost == mincost)
                pathcnt++;
            else
                pathcnt = 1;
            if (bestpath.size() == 0 || nowcost < mincost ||
                    nowcost == mincost && nowhappy > maxhappy ||
                    nowcost == mincost && nowhappy == maxhappy &&
                    nowpath.size() < bestpath.size())
            {
                mincost = nowcost;
                maxhappy = nowhappy;
                bestpath = nowpath;
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
                if (cost[index][i])
                {
                    nowcost += cost[index][i];
                    find(i);
                    nowcost -= cost[index][i];
                }
        }
        visit[index] = 0;
        nowpath.pop_back();
        nowhappy -= happy[index];
    }
}
int main(void)
{
    cin >> N >> K;
    char city[4];
    scanf("%s", city);
    indextoname[0] = nameint(city);
    for (int i = 1; i < N; i++)
    {
        int happyval;
        scanf("%s %d", city, &happyval);
        int nameval = nameint(city);
        if (city[0] == 'R' && city[1] == 'O' && city[2] == 'M')
            E = i;
        nametoindex[nameval] = i;
        indextoname[i] = nameval;
        happy[i] = happyval;
    }
    for (int i = 0; i < K; i++)
    {
        int c1, c2, c;
        char next[4];
        scanf("%s %s %d", city, next, &c);
        c1 = nametoindex[nameint(city)];
        c2 = nametoindex[nameint(next)];
        cost[c1][c2] = c;
        cost[c2][c1] = c;
    }
    find(0);
    printf("%d %d %d %d\n", pathcnt, mincost, maxhappy, maxhappy / (bestpath.size() - 1));
    for (int i = 0; i < bestpath.size(); i++)
    {
        if (i != 0)
            printf("->");
        int nameval = indextoname[bestpath[i]];
        putchar(nameval / 26 / 26 + 'A');
        putchar(nameval / 26 % 26 + 'A');
        putchar(nameval % 26 + 'A');
    }
    putchar('\n');
    return 0;
}
