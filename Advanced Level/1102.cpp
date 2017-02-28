#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

typedef struct
{
    int v;
    int l;
    int r;
} NODE;

int first;
void printinorder(int root, NODE* node)
{
    if (root == -1)
        return;
    else
    {
        printinorder(node[root].r, node);
        if (first)
            first = 0;
        else
            cout << " ";
        cout << node[root].v;
        printinorder(node[root].l, node);
    }
}

int main(void)
{
    int N;
    cin >> N;
    NODE node[N];
    int rootnode[N];
    for (int i = 0; i < N; i++)
        rootnode[i] = 1;
    for (int i = 0; i < N; i++)
    {
        char l[2], r[2];
        scanf("%s %s", l, r);
        node[i].v = i;
        if (l[0] == '-')
            node[i].l = -1;
        else
        {
            node[i].l = l[0] - '0';
            rootnode[l[0] - '0'] = 0;
        }
        if (r[0] == '-')
            node[i].r = -1;
        else
        {
            node[i].r = r[0] - '0';
            rootnode[r[0] - '0'] = 0;
        }
    }
    int root;
    for (int i = 0; i < N; i++)
        if (rootnode[i])
            root = i;
    list<int> level;
    first = 1;
    level.push_back(root);
    while (level.size())
    {
        if (first)
            first = 0;
        else
            cout << " ";
        int index = level.front();
        level.pop_front();
        cout << node[index].v;
        if (node[index].r != -1)
            level.push_back(node[index].r);
        if (node[index].l != -1)
            level.push_back(node[index].l);
    }
    cout << endl;
    first = 1;
    printinorder(root, node);
    cout << endl;
    return 0;
}
