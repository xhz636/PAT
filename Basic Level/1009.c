#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[81];
    int i, len;

    gets(s);
    len = strlen(s);
    while(s[0] == ' ')
        strcpy(s, s + 1);
    for(i = 0; i < len; i++)
        if(s[i] == ' ')
            s[i] = 0;
    for(i = len - 1; i > 0; i--)
        if(s[i] != 0 && s[i - 1] == 0)
            printf("%s ", s + i);
    printf("%s\n", s);

    return 0;
}
