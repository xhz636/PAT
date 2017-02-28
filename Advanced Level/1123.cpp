#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct
{
    int v;
    int l;
    int r;
    int lh;
    int rh;
} Node;
Node tree[20];
int root;

int max(int a, int b)
{
    return a > b ? a : b;
}

int insert(int p, int index)
{
    if (tree[p].v > tree[index].v)
    {
        if (tree[p].l == -1)
        {
            tree[p].l = index;
            tree[p].lh = 1;
        }
        else
        {
            tree[p].l = insert(tree[p].l, index);
            tree[p].lh = max(tree[tree[p].l].lh, tree[tree[p].l].rh) + 1;
        }
    }
    else
    {
        if (tree[p].r == -1)
        {
            tree[p].r = index;
            tree[p].rh = 1;
        }
        else
        {
            tree[p].r = insert(tree[p].r, index);
            tree[p].rh = max(tree[tree[p].r].lh, tree[tree[p].r].rh) + 1;
        }
    }
    int diff = tree[p].lh - tree[p].rh;
    if (diff > 1)
    {
        if (tree[tree[p].l].lh > tree[tree[p].l].rh)
        {
            int node = tree[p].l;
            tree[p].l = tree[node].r;
            tree[p].lh = tree[node].rh;
            tree[node].r = p;
            tree[node].rh = max(tree[p].lh, tree[p].rh) + 1;
            return node;
        }
        else
        {
            int node = tree[tree[p].l].r;
            tree[tree[p].l].r = tree[node].l;
            tree[tree[p].l].rh = tree[node].lh;
            tree[node].l = tree[p].l;
            tree[node].lh = max(tree[tree[p].l].lh, tree[tree[p].l].rh) + 1;
            tree[p].l = tree[node].r;
            tree[p].lh = tree[node].rh;
            tree[node].r = p;
            tree[node].rh = max(tree[p].lh, tree[p].rh) + 1;
            return node;
        }
    }
    else if (diff < -1)
    {
        if (tree[tree[p].r].rh > tree[tree[p].r].lh)
        {
            int node = tree[p].r;
            tree[p].r = tree[node].l;
            tree[p].rh = tree[node].lh;
            tree[node].l = p;
            tree[node].lh = max(tree[p].lh, tree[p].rh) + 1;
            return node;
        }
        else
        {
            int node = tree[tree[p].r].l;
            tree[tree[p].r].l = tree[node].r;
            tree[tree[p].r].lh = tree[node].rh;
            tree[node].r = tree[p].r;
            tree[node].rh = max(tree[tree[p].r].lh, tree[tree[p].r].rh) + 1;
            tree[p].r = tree[node].l;
            tree[p].rh = tree[node].lh;
            tree[node].l = p;
            tree[node].lh = max(tree[p].lh, tree[p].rh) + 1;
            return node;
        }
    }
    else
        return p;
}

int main(void)
{
    int N;
    cin >> N;
    cin >> tree[0].v;
    tree[0].l = -1;
    tree[0].r = -1;
    tree[0].lh = 0;
    tree[0].rh = 0;
    root = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> tree[i].v;
        tree[i].l = -1;
        tree[i].r = -1;
        tree[i].lh = 0;
        tree[i].rh = 0;
        root = insert(root, i);
    }
    queue<int> level;
    level.push(root);
    int complete = 1;
    int end = 0;
    while (level.size())
    {
        int node = level.front();
        level.pop();
        if (node != root)
            cout << " ";
        cout << tree[node].v;
        if (tree[node].l != -1)
            level.push(tree[node].l);
        if (tree[node].r != -1)
            level.push(tree[node].r);
        if (end)
        {
            if (tree[node].l != -1 || tree[node].r != -1)
                complete = 0;
        }
        else
        {
            if (tree[node].l == -1 && tree[node].r != -1)
                complete = 0;
        }
        if (tree[node].l == -1 || tree[node].r == -1)
            end = 1;
    }
    cout << endl;
    if (complete)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
