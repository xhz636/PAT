#include<stdio.h>

int main(void)
{
    int n, count;

    scanf("%d", &n);
    count = 0;
    while(n != 1)
    {
        if(n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
        count++;
    }
    printf("%d\n", count);

    return 0;
}
