#include<stdio.h>
#include<math.h>

int isprime(int n)
{
    int i;

    if(n < 2)
        return 0;
    for(i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int countprime(int num, int count, int nowcount)
{
    while(count < nowcount)
    {
        num++;
        if(isprime(num))
            count++;
    }

    return num;
}

int main(void)
{
    int m, n, i, count;
    int prime, index, num;

    scanf("%d %d", &m, &n);

    prime = 2;
    index = 1;
    for(i = m, count = 0; i <= n; i++)
    {
        num = countprime(prime, index, i);
        prime = num;
        index = i;
        if(count == 0)
            printf("%d", num);
        else
            printf(" %d", num);
        count++;
        if(count == 10 || i == n)
        {
            putchar('\n');
            count = 0;
        }
    }

    return 0;
}
