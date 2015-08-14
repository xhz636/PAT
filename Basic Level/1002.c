#include<stdio.h>
#include<string.h>

void read(int sum)
{
    if(sum < 10)
    {
        switch(sum)
        {
            case 0: printf("ling"); break;
            case 1: printf("yi"); break;
            case 2: printf("er"); break;
            case 3: printf("san"); break;
            case 4: printf("si"); break;
            case 5: printf("wu"); break;
            case 6: printf("liu"); break;
            case 7: printf("qi"); break;
            case 8: printf("ba"); break;
            case 9: printf("jiu"); break;
        }
        return;
    }
    else
    {
        read(sum / 10);
        putchar(' ');
        read(sum % 10);
    }

    return;
}

int main(void)
{
    char s[101];
    int sum, i;

    gets(s);
    for(i = 0, sum = 0; i < strlen(s); i++)
        sum += s[i] - '0';
    read(sum);

    return 0;
}
