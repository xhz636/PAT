#include<stdio.h>

int main(void)
{
    int t, a, b, c, i, sum;

    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", i);
        sum = a + b;
        if(a > 0 && b > 0 && sum < 0)
            printf("true\n");
        else if(a < 0 && b < 0 && sum > 0)
            printf("false\n");
        else if(sum > c)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}
