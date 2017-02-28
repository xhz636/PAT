#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct
{
    int val;
    int left;
    int right;
} Node;
Node node[1000];

int insert(int root, int index)
{
    if (node[index].val <= node[root].val)
    {
        if (node[root].left == -1)
        {
            node[root].left = index;
            return 1;
        }
        else
        {
            return insert(node[root].left, index) + 1;
        }
    }
    else
    {
        if (node[root].right == -1)
        {
            node[root].right = index;
            return 1;
        }
        else
        {
            return insert(node[root].right, index) + 1;
        }
    }
}

int depth, n1, n2;
void find(int root, int cnt)
{
    if (root == -1)
        return;
    else
    {
        if (cnt == depth)
            n1++;
        else if (cnt == depth - 1)
            n2++;
        find(node[root].left, cnt + 1);
        find(node[root].right, cnt + 1);
    }
}

int main(void)
{
    int N;
    cin >> N;
    int nodecnt = 0;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        node[nodecnt].val = val;
        node[nodecnt].left = -1;
        node[nodecnt].right = -1;
        if (nodecnt != 0)
        {
            int d = insert(0, nodecnt);
            if (depth < d)
                depth = d;
        }
        nodecnt++;
    }
    find(0, 0);
    printf("%d + %d = %d\n", n1, n2, n1 + n2);
    return 0;
}
