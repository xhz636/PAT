#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[10000], output[20000], t;
    int exp, e, i, j, head;

    gets(s);
    e = (int)(strchr(s, 'E') - s);
    for(i = e + 2, exp = 0; i < strlen(s); i++)
        exp = exp * 10 + s[i] - '0';
    for(i = 1, j = 10000; i < e; i++, j++)
        output[j] = s[i];
    output[j] = 0;
    if(s[e + 1] == '-')
    {
        for(i = 10000; i > 10000 - exp; i--)
        {
            t = output[i];
            output[i] = output[i + 1];
            output[i + 1] = t;
            output[i - 1] = '0';
        }
        head = i;
    }
    else
    {
        for(i = 10001; i < 10001 + exp; i++)
        {
            if(output[i] != 0)
            {
                t = output[i];
                output[i] = output[i + 1];
                output[i + 1] = t;
                if(output[i + 2] == 0)
                    output[i + 1] = 0;
            }
            else
            {
                output[i] = '0';
                output[i + 1] = 0;
            }
        }
        head = 10000;
    }
    if(s[0] == '-')
        output[--head] = '-';
    printf("%s\n", output + head);

    return 0;
}
