#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[1001], q[1001];
    int i, j, b, r, t, first;

    scanf("%s %d", a, &b);
    for(i = j = r = t = 0, first = 1; i < strlen(a);)
    {
        t = r * 10 + a[i++] - '0';
        r = t % b;
        if(first == 1 && t / b == 0)
            continue;
        else
        {
            q[j++] = t / b + '0';
            first = 0;
        }
    }
    q[j] = 0;
    if(strlen(q) == 0)
    {
        q[0] = '0';
        q[1] = 0;
    }
    printf("%s %d\n", q, r);

    return 0;
}
