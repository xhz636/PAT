#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Bird[10001];

int find(int B)
{
    if (Bird[B] > 0)
        return find(Bird[B]);
    else
        return B;
}

void merge(int B1, int B2)
{
    int R1 = find(B1);
    int R2 = find(B2);
    if (R1 == R2)
        return;
    if (Bird[R1] > Bird[R2])
        Bird[R1] = R2;
    else if (Bird[R1] < Bird[R2])
        Bird[R2] = R1;
    else
    {
        Bird[R1] = R2;
        Bird[R2]--;
    }
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K;
        scanf("%d", &K);
        int first;
        for (int j = 0; j < K; j++)
        {
            if (j == 0)
            {
                scanf("%d", &first);
                if (Bird[first] == 0)
                    Bird[first] = -1;
            }
            else
            {
                int next;
                scanf("%d", &next);
                if (Bird[next] == 0)
                    Bird[next] = -1;
                merge(first, next);
            }
        }
    }
    int index = 1;
    int cnt = 0;
    while (Bird[index])
    {
        if (Bird[index] < 0)
            cnt++;
        index++;
    }
    cout << cnt << " " << index - 1 << endl;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int B1, B2;
        scanf("%d %d", &B1, &B2);
        if (find(B1) == find(B2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
