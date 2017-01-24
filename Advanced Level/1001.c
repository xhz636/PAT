#include<stdio.h>

void formatp(int a, int count)
{
    if(a < 10)
    {
        printf("%d", a);
        if(count % 3 == 0 && count != 0)
            putchar(',');
    }
    else
    {
        formatp(a / 10, count + 1);
        formatp(a % 10, count);
    }

    return;
}

int main(void)
{
    int a, b, c;

    scanf("%d %d", &a, &b);
    c = a + b;
    if(c < 0)
    {
        putchar('-');
        formatp(-c, 0);
    }
    else
        formatp(c, 0);

    return 0;
}
