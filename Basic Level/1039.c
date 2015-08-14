#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[1001], n[1001];
    char scount[256] = {0}, ncount[256] = {0};
    int i, less = 0;

    gets(s);
    gets(n);
    for(i = 0; i < strlen(s); i++)
        scount[s[i]]++;
    for(i = 0; i < strlen(n); i++)
        ncount[n[i]]++;
    for(i = 0; i < 256; i++)
        less += ncount[i] > scount[i] ? ncount[i] - scount[i] : 0;
    if(less > 0)
        printf("No %d\n", less);
    else
        printf("Yes %d", strlen(s) - strlen(n));
    
    return 0;
}
