#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

int K[1001];
int Left[1001];
int Right[1001];
int complete(int num)
{
    int count = 1;
    while (count < num)
        count = count * 2 + 1;
    return count;
}
int build(int l, int r)
{
    if (l == r)
        return l;
    else if (l > r)
        return 0;
    else
    {
        int lc, rc, m;
        rc = (r - l) / 2;
        lc = r - l - rc;
        m = l + lc;
        int lcp = complete(lc);
        int rcp = complete(rc);
        if (lcp != lc && rcp != rc)
        {
            rcp = (rcp - 1) / 2;
            if (rc - rcp > lcp - lc)
                m += lcp - lc;
            else
                m += rc - rcp;
        }
        Left[m] = build(l, m - 1);
        Right[m] = build(m + 1, r);
        return m;
    }
}
void show(int root)
{
    queue<int> Q;
    Q.push(root);
    while (Q.size())
    {
        if (Q.front() != root)
            putchar(' ');
        printf("%d", K[Q.front()]);
        if (Left[Q.front()])
            Q.push(Left[Q.front()]);
        if (Right[Q.front()])
            Q.push(Right[Q.front()]);
        Q.pop();
    }
}
int main(void)
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &K[i]);
    sort(K, K + N + 1);
    int root = build(1, N);
    show(root);
    putchar('\n');
    return 0;
}
