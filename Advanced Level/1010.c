#include<stdio.h>
#include<string.h>

int char2int(char c)
{
    int num;
    
    if(c >= '0' && c <= '9')
        num = c - '0';
    else if(c >= 'a' && c <= 'z')
        num = c - 'a' + 10;
    
    return num;
}

int find_min_radix(char* s)
{
    int min = 2;
    int i;

    for(i = 0; i < strlen(s); i++)
        if(char2int(s[i]) >= min)
            min = char2int(s[i]) + 1;
    
    return min;
}

long long int str2lld(char* s, long long int radix)
{
    int i;
    long long int num = 0, exp = 1;

    for(i = strlen(s) - 1; i >= 0; i--)
    {
        num += char2int(s[i]) * exp;
        exp *= radix;
    }

    return num;
}

int cmp(char* s, long long int radix, long long int target)
{
    int i;
    long long int num = 0, exp = 1;

    for(i = strlen(s) - 1; i >= 0; i--)
    {
        num += char2int(s[i]) * exp;
        exp *= radix;
        if(num > target)
            return 1;
    }
    if(num < target)
        return -1;
    else
        return 0;
}

long long int search(char* s, long long int min, long long int max, long long int target)
{
    long long int mid = min;
    int result;

    while(min <= max)
    {
        result = cmp(s, mid, target);
        if(result > 0)
            max = mid - 1;
        else if(result < 0)
            min = mid + 1;
        else
            return mid;
        mid = (min + max) / 2;
    }

    return -1;
}

int main(void)
{
    char n[3][11];
    int tag, digit;
    long long int radix;
    long long int i, num;

    scanf("%s %s %d %lld", n[0], n[1], &tag, &radix);
    if(tag == 2)
    {
        strcpy(n[2], n[0]);
        strcpy(n[0], n[1]);
        strcpy(n[1], n[2]);
    }
    i = find_min_radix(n[1]);
    num = str2lld(n[0], radix);
    if(strlen(n[1]) == 1)
        i = char2int(n[1][0]) + 1;
    else
        i = search(n[1], i, num, num);
    if(i > 0 && str2lld(n[1], i) == num)
        printf("%lld\n", i);
    else
        printf("Impossible\n");

    return 0;
}
