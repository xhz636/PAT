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

int main(void)
{
    int n, i, last, count;

    scanf("%d", &n);
    for(i = 5, last = 3, count = 0; i <= n; i++)
        if(isprime(i))
        {
            if(i - last == 2)
                count++;
            last = i;
        }
    printf("%d\n", count);

    return 0;
}
