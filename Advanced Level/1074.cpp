#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct
{
    int val;
    int next;
} Node;
Node List[100000];
int N, K;
int Reverse(int H, int count)
{
    if (N < K)
        return H;
    N -= K;
    int prev = H;
    int now = List[H].next;
    while (--count)
    {
        int next = List[now].next;
        List[now].next = prev;
        prev = now;
        now = next;
    }
    List[H].next = Reverse(now, K);
    return prev;
}

int main(void)
{
    int Head;
    cin >> Head >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &List[addr].val, &List[addr].next);
    }
    int index = Head;
    N = 0;
    while (index != -1)
    {
        N++;
        index = List[index].next;
    }
    Head = Reverse(Head, K);
    while (Head != -1)
    {
        printf("%05d %d", Head, List[Head].val);
        if (List[Head].next != -1)
            printf(" %05d\n", List[Head].next);
        else
            printf(" -1\n");
        Head = List[Head].next;
    }
    return 0;
}
