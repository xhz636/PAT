#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

typedef struct
{
    int p;
    int l;
    int r;
} Node;

int main(void)
{
    int N;
    cin >> N;
    Node node[N];
    for (int i = 0; i < N; i++)
        node[i].p = node[i].l = node[i].r = -1;
    char l[3], r[3];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", l, r);
        int num;
        if (l[0] != '-')
        {
            sscanf(l, "%d", &num);
            node[i].l = num;
            node[num].p = i;
        }
        if (r[0] != '-')
        {
            sscanf(r, "%d", &num);
            node[i].r = num;
            node[num].p = i;
        }
    }
    int root;
    for (int i = 0; i < N; i++)
        if (node[i].p == -1)
        {
            root = i;
            break;
        }
    list<int> order;
    order.push_back(root);
    int complete = 1;
    int leaves = 0;
    int last;
    while (order.size())
    {
        last = order.front();
        Node now = node[last];
        order.pop_front();
        if (now.l != -1)
            order.push_back(now.l);
        if (now.r != -1)
            order.push_back(now.r);
        if (now.l == -1 && now.r != -1 ||
                leaves && (now.l != -1 || now.r != -1))
        {
            complete = 0;
            break;
        }
        if (now.l == -1 || now.r == -1)
            leaves = 1;
    }
    if (complete)
        printf("YES %d\n", last);
    else
        printf("NO %d\n", root);
    return 0;
}
