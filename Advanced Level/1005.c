#include<stdio.h>
#include<string.h>

int count(char* str);
void read_digital(int num);
void read_english(int num);

int main(void)
{
    char str[102];
    int num;

    gets(str);
    num = count(str);
    read_digital(num);
    putchar('\n');
    
    return 0;
}

int count(char* str)
{
    int sum = 0;
    int i;

    for(i = 0; i < strlen(str); i++)
        sum += str[i] - '0';

    return sum;
}

void read_digital(int num)
{
    if(num < 10)
        read_english(num);
    else
    {
        read_digital(num / 10);
        putchar(' ');
        read_digital(num % 10);
    }

    return;
}

void read_english(int num)
{
    switch(num)
    {
        case 0:printf("zero"); break;
        case 1:printf("one"); break;
        case 2:printf("two"); break;
        case 3:printf("three"); break;
        case 4:printf("four"); break;
        case 5:printf("five"); break;
        case 6:printf("six"); break;
        case 7:printf("seven"); break;
        case 8:printf("eight"); break;
        case 9:printf("nine"); break;
    }

    return;
}
