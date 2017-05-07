#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

typedef struct
{
    int val;
    int left;
    int right;
} Node;
Node Tree[30];
int first = 1;
void spaceprint(int num)
{
    if (first)
        first = 0;
    else
        putchar(' ');
    printf("%d", num);
}
void show(int node)
{
    if (node == -1)
        return;
    else
    {
        show(Tree[node].left);
        show(Tree[node].right);
        spaceprint(Tree[node].val);
    }
}
int Pre[30];
int In[30];
int build(int p, int il, int ir)
{
    if (il >= ir)
        return -1;
    else if (il == ir - 1)
        return p;
    else
    {
        int mid;
        for (int i = il; i < ir; i++)
            if (Pre[p] == In[i])
            {
                mid = i;
                break;
            }
        Tree[p].left = build(p + 1, il, mid);
        Tree[p].right = build(p + mid - il + 1, mid + 1, ir);
        return p;
    }
}
int main(void)
{
    int N;
    cin >> N;
    int index = 0;
    stack<int> order;
    int preindex = 0, inindex = 0;
    for (int i = 0; i < N * 2; i++)
    {
        char op[5];
        int val;
        scanf("%s", op);
        if (op[1] == 'u')
        {
            scanf("%d", &val);
            Tree[index].val = val;
            Tree[index].left = -1;
            Tree[index].right = -1;
            Pre[preindex++] = index;
            order.push(index++);
        }
        else
        {
            In[inindex++] = order.top();
            order.pop();
        }
    }
    build(0, 0, inindex);
    show(0);
    putchar('\n');
    return 0;
}
