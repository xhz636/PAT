#include<stdio.h>

int main(void)
{
    int sum = -1, start, end;
    int maybesum = 0, maybestart = -1;
    int all_negative = 1, first, last;
    int i, k, num;

    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &num);
        if(i == 0)
            first = num;
        if(i == k - 1)
            last = num;
        if(all_negative && num >= 0)
            all_negative = 0;
        maybesum += num;
        if(maybestart == -1)
            maybestart = num;
        if(maybesum > sum)
        {
            sum = maybesum;
            start = maybestart;
            end = num;
        }
        else if(maybesum < 0)
        {
            maybesum = 0;
            maybestart = -1;
        }
    }
    if(all_negative)
        printf("0 %d %d\n", first, last);
    else
        printf("%d %d %d\n", sum, start, end);

    return 0;
}
