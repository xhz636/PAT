#include<stdio.h>

int main(void)
{
    int n, i;
    int now = 0, next;
    int time = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &next);
        if(next > now)
            time += (next - now) * 6;
        else if(next < now)
            time += (now - next) * 4;
        time += 5;
        now = next;
    }
    printf("%d\n", time);

    return 0;
}
