#include<stdio.h>

int main(void)
{
    int k, n, i, j;
    int input[100], temp;

    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &input[i]);
    }
    for(i = 0; i < k; i++)
    {
        if(input[i] == 1)
            continue;
        n = input[i];
        while(n != 1)
        {
            if(n % 2 == 0)
                n /= 2;
            else
                n = (3 * n + 1) / 2;
            for(j = 0; j < k; j++)
                if(input[j] == n)
                    input[j] = 1;
        }
    }
    for(i = 0; i < k - 1; i++)
    {
        for(j = 0; j < k - i - 1; j++)
            if(input[j] < input[j + 1])
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
    }
    printf("%d", input[0]);
    for(i = 1; i < k; i++)
        if(input[i] != 1)
            printf(" %d", input[i]);
    putchar('\n');

    return 0;
}
