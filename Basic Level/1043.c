#include<stdio.h>

int main(void)
{
    int count[128];
    char pattern[7] = "PATest";
    char c;
    int i;

    for(i = 0; i < 128; i++)
        count[i] = 0;
    while((c = getchar()) != '\n')
        count[c]++;
    while(count['P'] != 0 || count['A'] != 0 || count['T'] != 0
            || count['e'] != 0 || count['s'] != 0 || count['t'] != 0)
    {
        for(i = 0; i < 6; i++)
            if(count[pattern[i]] != 0)
            {
                putchar(pattern[i]);
                count[pattern[i]]--;
            }
    }
    putchar('\n');

    return 0;
}
