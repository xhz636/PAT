#include<stdio.h>
#include<stdlib.h>

int cmp(int *a, int *b)
{
    return *a - *b;
}

int equal(int next[100], int center[100], int n)
{
    int i;

    for(i = 0; i < n; i++)
        if(next[i] != center[i])
            return 0;

    return 1;
}

int main(void)
{
    int n, i, j, begin[100], center[100], next[100], merge, flag = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &begin[i]);
        next[i] = begin[i];
    }
    for(i = 0; i < n; i++)
        scanf("%d", &center[i]);
    for(i = 1; i < n; i++)
    {
        if(equal(next, center, n))
            flag = 1;
        if(next[i] > next[i - 1])
            continue;
        else
        {
            qsort(next, i + 1, sizeof(int), cmp);
            if(flag)
            {
                printf("Insertion Sort\n");
                printf("%d", next[0]);
                for(i = 1; i < n; i++)
                    printf(" %d", next[i]);
                putchar('\n');
                return 0;
            }
        }
    }
    merge = 1;
    flag = 0;
    for(i = 0; i < n; i++)
    {
        merge *= 2;
        if(equal(begin, center, n))
            flag = 1;
        for(j = 0; j < n; j += merge)
            qsort(begin + j, n - j < merge ? n - j : merge, sizeof(int), cmp);
        if(flag)
        {
            printf("Merge Sort\n");
            printf("%d", begin[0]);
            for(i = 1; i < n; i++)
                printf(" %d", begin[i]);
            putchar('\n');
            return 0;
        }
    }

    return 0;
}
