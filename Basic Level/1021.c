#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[1001];
    int digit[10] = {0}, i;

    gets(s);
    for(i = 0; i < strlen(s); i++)
        digit[s[i] - '0']++;
    for(i = 0; i < 10; i++)
        if(digit[i] != 0)
            printf("%d:%d\n", i, digit[i]);

    return 0;
}
