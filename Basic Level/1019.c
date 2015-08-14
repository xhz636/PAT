#include<stdio.h>

void numsort(int a, int *b, int *c)
{
    int s[4], t;
    int i, j;

    for(i = 0; i < 4; i++)
    {
        s[i] = a % 10;
        a /= 10;
    }
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3 - i; j++)
            if(s[j] < s[j + 1])
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
    for(i = 0, *b = 0; i < 4; i++)
        *b = *b * 10 + s[i];
    for(i = 3, *c = 0; i >= 0; i--)
        *c = *c * 10 + s[i];

    return;
}

int main(void)
{
    int a, b, c;

    scanf("%d", &a);
    if(a == 6174)
        printf("7641 - 1467 = 6174\n");
    else
        while(a != 6174 && a != 0)
        {
            numsort(a, &b, &c);
            a = b - c;
            printf("%04d - %04d = %04d\n", b, c, a);
        }

    return 0;
}
