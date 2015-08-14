#include<stdio.h>

int main(void)
{
    int coe, exp;

    scanf("%d %d", &coe, &exp);
    if(exp == 0)
        printf("0 0");
    else
        printf("%d %d", coe * exp, exp - 1);
    while(scanf("%d %d", &coe, &exp) != EOF)
    {
        if(exp != 0)
            printf(" %d %d", coe * exp, exp - 1);
    }
    putchar('\n');

    return 0;
}
