#include<stdio.h>

struct fraction
{
    long numerator;
    long denominator;
} a, b, c;

long gcd(long a, long b)
{
    long c = 0;
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void print_fraction(struct fraction a)
{
    long t;
    if(a.denominator == 0)
    {
        printf("Inf");
        return;
    }
    if(a.numerator == 0)
    {
        printf("0");
        return;
    }
    if(a.denominator < 0)
    {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    t = gcd(a.numerator, a.denominator);
    if(a.numerator < 0)
        a.numerator = -(-a.numerator / t);
    else
        a.numerator /= t;
    a.denominator /= t;
    if(a.numerator < 0)
    {
        a.numerator = -a.numerator;
        if(a.numerator > a.denominator && a.numerator % a.denominator != 0)
            printf("(-%ld %ld/%ld)", a.numerator / a.denominator, a.numerator % a.denominator, a.denominator);
        else if(a.numerator % a.denominator == 0)
            printf("(-%ld)", a.numerator / a.denominator);
        else
            printf("(-%ld/%ld)", a.numerator, a.denominator);
    }
    else
    {
        if(a.numerator > a.denominator && a.numerator % a.denominator != 0)
            printf("%ld %ld/%ld", a.numerator / a.denominator, a.numerator % a.denominator, a.denominator);
        else if(a.numerator % a.denominator == 0)
            printf("%ld", a.numerator / a.denominator);
        else
            printf("%ld/%ld", a.numerator, a.denominator); 
    }
}

int main(void)
{
    scanf("%ld%*c%ld %ld%*c%ld", &a.numerator, &a.denominator, &b.numerator, &b.denominator);
    c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    print_fraction(a);
    printf(" + ");
    print_fraction(b);
    printf(" = ");
    print_fraction(c);
    putchar('\n');
    c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    print_fraction(a);
    printf(" - ");
    print_fraction(b);
    printf(" = ");
    print_fraction(c);
    putchar('\n');
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.denominator;
    print_fraction(a);
    printf(" * ");
    print_fraction(b);
    printf(" = ");
    print_fraction(c);
    putchar('\n');
    c.numerator = a.numerator * b.denominator;
    c.denominator = a.denominator * b.numerator;
    print_fraction(a);
    printf(" / ");
    print_fraction(b);
    printf(" = ");
    print_fraction(c);
    putchar('\n');

    return 0;
}
