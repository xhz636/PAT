#include<stdio.h>
#include<string.h>

char *low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char *high[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(void)
{
    int N;
    int i, j, k;
    char input[16];
    int num;
    int count;
    char mars[2][5];

    scanf("%d", &N);
    getchar();
    for(i = 0; i < N; i++)
    {
        gets(input);
        if(input[0] >= '0' && input[0] <= '9')
        {
            sscanf(input, "%d", &num);
            if(num < 13)
                printf("%s\n", low[num]);
            else if(num % 13 != 0)
                printf("%s %s\n", high[num / 13 - 1], low[num % 13]);
            else
                printf("%s\n", high[num / 13 - 1]);
        }
        else
        {
            count = 1;
            for(j = 0; j < strlen(input); j++)
                if(input[j] == ' ')
                {
                    count = 2;
                    break;
                }
            if(count == 1)
                sscanf(input, "%s", mars[0]);
            else
                sscanf(input, "%s %s", mars[0], mars[1]);
            num = 0;
            for(j = 0; j < count; j++)
            {
                for(k = 0; k < 12; k++)
                    if(strcmp(mars[j], high[k]) == 0)
                    {
                        num += (k + 1) * 13;
                        continue;
                    }
                for(k = 0; k < 13; k++)
                    if(strcmp(mars[j], low[k]) == 0)
                    {
                        num += k;
                        continue;
                    }
            }
            printf("%d\n", num);
        }
    }

    return 0;
}
