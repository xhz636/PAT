#include<stdio.h>

int main(void)
{
    int n, i, score, a[100000] = {0}, index, maxindex;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &index, &score);
        a[index] += score;
    }
    for(i = 1, maxindex = 0; i < n + 1; i++)
        if(a[i] > a[maxindex])
            maxindex = i;
    printf("%d %d\n", maxindex, a[maxindex]);

    return 0;
}
