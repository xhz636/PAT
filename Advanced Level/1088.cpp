#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    return a % b ? gcd(b, a % b) : b;
}
void simply(long long int& a, long long int& b)
{
    if (a == 0 || b == 0)
        return;
    else
    {
        int neg = a < 0;
        if (neg)
            a = -a;
        long long int num = gcd(a, b);
        a /= num;
        b /= num;
        if (neg)
            a = -a;
    }
}
void printnum(long long int a, long long int b)
{
    if (b == 0)
        printf("Inf");
    else if (a == 0)
        printf("0");
    else
    {
        int neg = a < 0;
        if (neg)
        {
            printf("(-");
            a = -a;
        }
        if (a >= b)
        {
            printf("%lld", a / b);
            if (a % b != 0)
                printf(" %lld/%lld", a % b, b);
        }
        else
        {
            printf("%lld/%lld", a, b);
        }
        if (neg)
            putchar(')');
    }
}
int main(void)
{
    long long int a1, b1, a2, b2, a3, b3;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    simply(a1, b1);
    simply(a2, b2);
    a3 = a1 * b2 + a2 * b1;
    b3 = b1 * b2;
    simply(a3, b3);
    printnum(a1, b1);
    printf(" + ");
    printnum(a2, b2);
    printf(" = ");
    printnum(a3, b3);
    putchar('\n');
    a3 = a1 * b2 - a2 * b1;
    b3 = b1 * b2;
    simply(a3, b3);
    printnum(a1, b1);
    printf(" - ");
    printnum(a2, b2);
    printf(" = ");
    printnum(a3, b3);
    putchar('\n');
    a3 = a1 * a2;
    b3 = b1 * b2;
    simply(a3, b3);
    printnum(a1, b1);
    printf(" * ");
    printnum(a2, b2);
    printf(" = ");
    printnum(a3, b3);
    putchar('\n');
    a3 = a1 * b2;
    b3 = b1 * a2;
    if (b3 < 0)
    {
        a3 = -a3;
        b3 = -b3;
    }
    simply(a3, b3);
    printnum(a1, b1);
    printf(" / ");
    printnum(a2, b2);
    printf(" = ");
    printnum(a3, b3);
    putchar('\n');
    return 0;
}
