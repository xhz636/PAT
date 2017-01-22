#include<stdio.h>

int main(void)
{
    int count[26];
    char c;
    int i;
    int max;

    for(i = 0; i < 26; i++)
        count[i] = 0;
    while((c = getchar()) != '\n')
    {
        if(c >= 'A' && c <= 'Z')
            count[c - 'A']++;
        else if(c >= 'a' && c <= 'z')
            count[c - 'a']++;
    }
    max = 0;
    for(i = 1; i < 26; i++)
        if(count[i] > count[max])
            max = i;
    printf("%c %d\n", max + 'a', count[max]);

    return 0;
}
