#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char c, key[100001], broken[256] = {0};
    int i, j, shift;

    gets(key);
    for(i = 0; i < strlen(key); i++)
        broken[key[i]] = 1;
    while((c = getchar()) != EOF)
    {
        if(broken['+'] && isupper(c))
            continue;
        if(broken[c])
            continue;
        if(islower(c) && broken[c - 0x20])
            continue;
        putchar(c);
    }

    return 0;
}
