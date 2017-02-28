#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int pre[30], post[30];
int l[30], r[30];
int build(int prel, int prer, int postl, int postr)
{
    if (prel >= prer)
        return 1;
    if (pre[prel] != post[postr - 1])
        return 0;
    int cnt = 0;
    for (int i = 0; i < prer - prel; i++)
    {
        int l = build(prel + 1, prel + 1 + i, postl, postl + i);
        int r = build(prel + 1 + i, prer, postl + i, postr - 1);
        cnt += l * r;
    }
    return cnt;
}

int get(int& n, int prel, int prer, int postl, int postr)
{
    if (prel >= prer)
        return 1;
    if (pre[prel] != post[postr - 1])
        return 0;
    n = prel;
    for (int i = 0; i < prer - prel; i++)
    {
        if(get(l[n], prel + 1, prel + 1 + i, postl, postl + i)
                && get(r[n], prel + 1 + i, prer, postl + i, postr - 1))
            return 1;
    }
    return 0;
}

int first = 1;
void show(int n)
{
    if (n == -1)
        return;
    show(l[n]);
    if (!first)
        cout << " ";
    cout << pre[n];
    first = 0;
    show(r[n]);
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> pre[i];
    for (int i = 0; i < N; i++)
        cin >> post[i];
    if (build(0, N, 0, N) == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = 0; i < N; i++)
    {
        l[i] = -1;
        r[i] = -1;
    }
    int root;
    get(root, 0, N, 0, N);
    show(root);
    putchar('\n');
    return 0;
}
