#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int origin[100];
int insert[100];
int list[100];
int N;
int isort(int step)
{
    int i;
    if (step == 0)
    {
        insert[0] = origin[0];
        return 1;
    }
    for (i = step; i > 0; i--)
    {
        if (insert[i - 1] > origin[step])
            insert[i] = insert[i - 1];
        else
            break;
    }
    insert[i] = origin[step];
    return step + 1;
}
int msort(int step)
{
    int temp[100];
    int index = 0;
    int i1 = 0, i2 = step;
    while (i1 + step <= N)
    {
        int i = i1, j = i2;
        while (i < i1 + step && i < N && j < i2 + step && j < N)
        {
            if (origin[i] < origin[j])
                temp[index++] = origin[i++];
            else
                temp[index++] = origin[j++];
        }
        while (i < i1 + step && i < N)
            temp[index++] = origin[i++];
        while (j < i2 + step && j < N)
            temp[index++] = origin[j++];
        i1 += step * 2;
        i2 += step * 2;
    }
    for (int i = 0; i < i1; i++)
        origin[i] = temp[i];
    return step * 2;
}
int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &origin[i]);
        insert[i] = origin[i];
    }
    for (int i = 0; i < N; i++)
        scanf("%d", &list[i]);
    int step = 0;
    while (step < N)
    {
        step = isort(step);
        int is = 1;
        for (int i = 0; i < N; i++)
            if (list[i] != insert[i])
            {
                is = 0;
                break;
            }
        while (is)
        {
            step = isort(step);
            int same = 1;
            for (int i = 0; i < N; i++)
                if (list[i] != insert[i])
                {
                    same = 0;
                    break;
                }
            if (same)
                continue;
            printf("Insertion Sort\n");
            for (int i = 0; i < N; i++)
            {
                if (i != 0)
                    putchar(' ');
                printf("%d", insert[i]);
            }
            putchar('\n');
            return 0;
        }
    }
    step = 1;
    while (1)
    {
        step = msort(step);
        int is = 1;
        for (int i = 0; i < N; i++)
            if (list[i] != origin[i])
            {
                is = 0;
                break;
            }
        while (is)
        {
            step = msort(step);
            int same = 1;
            for (int i = 0; i < N; i++)
                if (list[i] != origin[i])
                {
                    same = 0;
                    break;
                }
            if (same)
                continue;
            printf("Merge Sort\n");
            for (int i = 0; i < N; i++)
            {
                if (i != 0)
                    putchar(' ');
                printf("%d", origin[i]);
            }
            putchar('\n');
            return 0;
        }
    }
    return 0;
}
