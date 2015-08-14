#include<stdio.h>

void dprint(int sum, int d)
{
    if(sum < d)
    {
        printf("%d", sum);
        return;
    }
    else
    {
        dprint(sum / d, d);
        dprint(sum % d, d);
    }

    return;
}

int main(void)
{
    int a, b, d;
    
    scanf("%d %d %d", &a, &b, &d);
    dprint(a + b, d);

    return 0;
}
