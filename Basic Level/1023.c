#include<stdio.h>

int main(void)
{
    int digit[10], i, j;

    for(i = 0; i < 10; i++)
        scanf("%d", &digit[i]);
    for(i = 1; i < 10; i++)
        if(digit[i] != 0)
        {
            printf("%d", i);
            digit[i]--;
            break;
        }
    for(i = 0; i < 10; i++)
        for(j = 0; j < digit[i]; j++)
            printf("%d", i);
    putchar('\n');

    return 0;
}
