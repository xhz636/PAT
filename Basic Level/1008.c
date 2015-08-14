#include<stdio.h>

int main(void)
{
    int n, m, i, index;
    int a[100];

    scanf("%d %d", &n, &m);
    while(m >= n)
        m %= n;
    for(i = 0, index = m; i < n; i++, index++)
    {
        if(index == n)
            index = 0;
        scanf("%d", &a[index]);
    }
    printf("%d", a[0]);
    for(i = 1; i < n; i++)
        printf(" %d", a[i]);
    putchar('\n');

    return 0;
}
