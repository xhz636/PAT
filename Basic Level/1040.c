#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[100001];
    long long int count, i, t = 0, mul = 0;

    gets(s);
    for(i = strlen(s) - 1, count = 0; i >= 0; i--)
    {
        if(s[i] == 'T')
            t++;
        if(s[i] == 'A')
            mul += t;
        if(s[i] == 'P')
            count += mul;
    }
    printf("%d\n", count % 1000000007);

    return 0;
}
