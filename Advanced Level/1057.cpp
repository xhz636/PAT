#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
using namespace std;

stack<int> S;
multiset<int, greater<int> > maxheap;
multiset<int, less<int> > minheap;
void pop()
{
    if (S.size())
    {
        printf("%d\n", S.top());
        multiset<int>::iterator it;
        if ((it = maxheap.find(S.top())) != maxheap.end())
            maxheap.erase(it);
        else if ((it = minheap.find(S.top())) != minheap.end())
            minheap.erase(it);
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.insert(*maxheap.begin());
            maxheap.erase(maxheap.begin());
        }
        else if (maxheap.size() < minheap.size())
        {
            maxheap.insert(*minheap.begin());
            minheap.erase(minheap.begin());
        }
        S.pop();
    }
    else
    {
        printf("Invalid\n");
    }
}
void median()
{
    if (S.size())
    {
        printf("%d\n", *maxheap.begin());
    }
    else
    {
        printf("Invalid\n");
    }
}
void push(int num)
{
    S.push(num);
    if (maxheap.size() <= minheap.size())
    {
        if (minheap.size() > 0 && num > *minheap.begin())
        {
            maxheap.insert(*minheap.begin());
            minheap.erase(minheap.begin());
            minheap.insert(num);
        }
        else
            maxheap.insert(num);
    }
    else
    {
        if (maxheap.size() > 0 && num < *maxheap.begin())
        {
            minheap.insert(*maxheap.begin());
            maxheap.erase(maxheap.begin());
            maxheap.insert(num);
        }
        else
            minheap.insert(num);
    }
}
int main(void)
{
    int N;
    cin >> N;
    char Op[12];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", Op);
        if (Op[1] == 'o')
            pop();
        else if (Op[1] == 'e')
            median();
        else if (Op[1] == 'u')
        {
            int num;
            scanf("%d", &num);
            push(num);
        }
    }
    return 0;
}
