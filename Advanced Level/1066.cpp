#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct NODE
{
    int val;
    int l;
    int r;
    int h;
} Node[20];
int getheight(int node)
{
    if (node == -1)
        return 0;
    else
        return Node[node].h;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
void reh(int node)
{
    Node[node].h = max(getheight(Node[node].l),
                       getheight(Node[node].r)) + 1;
}
int add(int node, int index)
{
    if (Node[node].val > Node[index].val)
    {
        if (Node[node].l == -1)
            Node[node].l = index;
        else
            Node[node].l = add(Node[node].l, index);
    }
    else
    {
        if (Node[node].r == -1)
            Node[node].r = index;
        else
            Node[node].r = add(Node[node].r, index);
    }
    reh(node);
    int lh = getheight(Node[node].l);
    int rh = getheight(Node[node].r);
    if (lh - rh > 1)
    {
        int now = Node[node].l;
        if (getheight(Node[now].l) > getheight(Node[now].r))
        {
            Node[node].l = Node[now].r;
            reh(node);
            Node[now].r = node;
            reh(now);
            node = now;
        }
        else
        {
            int child = Node[node].l;
            now = Node[now].r;
            Node[node].l = Node[now].r;
            reh(node);
            Node[child].r = Node[now].l;
            reh(child);
            Node[now].l = child;
            Node[now].r = node;
            reh(now);
            node = now;
        }
    }
    else if (lh - rh < -1)
    {
        int now = Node[node].r;
        if (getheight(Node[now].r) > getheight(Node[now].l))
        {
            Node[node].r = Node[now].l;
            reh(node);
            Node[now].l = node;
            reh(now);
            node = now;
        }
        else
        {
            int child = Node[node].r;
            now = Node[now].l;
            Node[node].r = Node[now].l;
            reh(node);
            Node[child].l = Node[now].r;
            reh(child);
            Node[now].r = child;
            Node[now].l = node;
            reh(now);
            node = now;
        }
    }
    return node;
}
int main(void)
{
    int N;
    cin >> N;
    int root = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> Node[cnt].val;
        Node[cnt].l = -1;
        Node[cnt].r = -1;
        Node[cnt].h = 1;
        if (cnt)
            root = add(root, cnt);
        cnt++;
    }
    cout << Node[root].val << endl;
    return 0;
}
