#include<stdio.h>

int main(void)
{
    int a[5], a1_flag, a3_count, flag;
    int n, i, k;

    scanf("%d", &n);
    a[0] = a[1] = a[2] = a[3] = a[4] = a1_flag = a3_count = 0;
    flag = 1;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &k);
        switch(k % 5)
        {
            case 0:{
                       if(k % 2 == 0)
                           a[0] += k;
                       break;
                   }
            case 1:{
                       a[1] += flag * k;
                       flag = -flag;
                       a1_flag = 1;
                       break;
                   }
            case 2:{
                       a[2]++;
                       break;
                   }
            case 3:{
                       a[3] += k;
                       a3_count++;
                       break;
                   }
            case 4:{
                       if(k > a[4])
                           a[4] = k;
                       break;
                   }
        }
    }
    if(a[0] == 0)
        printf("N");
    else
        printf("%d", a[0]);
    for(i = 1; i < 5; i++)
    {
        if(i == 3)
            if(a[3] == 0)
                printf(" N");
            else
                printf(" %.1f", (double)a[3] / (double)a3_count);
        else if(i == 1)
            if(a1_flag == 0)
                printf(" N");
            else
                printf(" %d", a[1]);
        else
            if(a[i] == 0)
                printf(" N");
            else
                printf(" %d", a[i]);
    }
    putchar('\n');

    return 0;
}
