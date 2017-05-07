#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    char line[20000];
    scanf("%s", line);
    char numsign, intdigit;
    char num[10000];
    int exp;
    numsign = line[0];
    intdigit = line[1];
    int index = 0;
    for (int i = 3; line[i] != 'E'; i++)
        num[index++] = line[i];
    num[index] = '\0';
    sscanf(line + index + 4, "%d", &exp);
    if (numsign == '-')
        putchar(numsign);
    if (exp < 0)
    {
        printf("0.");
        while (++exp)
            putchar('0');
        printf("%c%s\n", intdigit, num);
    }
    else if (exp >= index)
    {
        printf("%c%s", intdigit, num);
        while (exp > index)
        {
            putchar('0');
            exp--;
        }
        putchar('\n');
    }
    else
    {
        putchar(intdigit);
        int i;
        for (i = 0; i < exp; i++)
            putchar(num[i]);
        putchar('.');
        printf("%s\n", num + i);
    }
    return 0;
}
