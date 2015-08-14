#include<stdio.h>

int main(void)
{
    char as, bs;
    int n, i, win = 0, lost = 0, draw = 0, a[3] = {0}, b[3] = {0};

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf(" %c %c", &as, &bs);
        if(as == bs)
            draw++;
        else if(as == 'C' && bs == 'J')
        {
            win++;
            a[1]++;
        }
        else if(as == 'C' && bs == 'B')
        {
            lost++;
            b[0]++;
        }
        else if(as == 'J' && bs == 'C')
        {
            lost++;
            b[1]++;
        }
        else if(as == 'J' && bs == 'B')
        {
            win++;
            a[2]++;
        }
        else if(as == 'B' && bs == 'C')
        {
            win++;
            a[0]++;
        }
        else if(as == 'B' && bs == 'J')
        {
            lost++;
            b[2]++;
        }
    }
    printf("%d %d %d\n", win, draw, lost);
    printf("%d %d %d\n", lost, draw, win);
    if(a[0] >= a[1] && a[0] >= a[2])
        putchar('B');
    else if(a[1] >= a[0] && a[1] >= a[2])
        putchar('C');
    else
        putchar('J');
    if(b[0] >= b[1] && b[0] >= b[2])
        printf(" B\n");
    else if(b[1] >= b[0] && b[1] >= b[2])
        printf(" C\n");
    else
        printf(" J\n");

    return 0;
}
