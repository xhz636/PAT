#include<stdio.h>

int main(void)
{
    int n, i;

    scanf("%d", &n);
    if(n > 99)
    {
        for(i = 0; i < n / 100; i++)
            putchar('B');
        n %= 100;
    }
    if(n > 9)
    {
        for(i = 0; i < n / 10; i++)
            putchar('S');
        n %= 10;
    }
    for(i = 1; i <= n; i++)
        putchar(i + '0');
    putchar('\n');

    return 0;
}
