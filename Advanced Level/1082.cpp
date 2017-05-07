#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char digit[10][6] =
{
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
};
char powname[4][6] =
{
    "",
    "Shi",
    "Bai",
    "Qian"
};
int first = 1;
void spaceprint(const char* num)
{
    if (num[0] == '\0')
        return;
    if (first)
        first = 0;
    else
        putchar(' ');
    printf("%s", num);
}
void show(int num, int pow, int withnum)
{
    if (num < 10)
    {
        if (num > 0)
        {
            spaceprint(digit[num]);
            spaceprint(powname[pow]);
        }
    }
    else
    {
        show(num / 10, pow + 1, num % 10 != 0);
        if (num % 10 != 0 || withnum)
            spaceprint(digit[num % 10]);
        if (num % 10 != 0)
            spaceprint(powname[pow]);
    }
}
int main(void)
{
    int N;
    cin >> N;
    if (N < 0)
    {
        spaceprint("Fu");
        N = -N;
    }
    if (N == 0)
    {
        spaceprint("ling");
    }
    else
    {
        if (N >= 100000000)
        {
            show(N / 100000000, 0, 0);
            spaceprint("Yi");
            N %= 100000000;
            if (N < 10000000)
                spaceprint("ling");
        }
        if (N >= 10000)
        {
            show(N / 10000, 0, 0);
            spaceprint("Wan");
            N %= 10000;
            if (N < 1000)
                spaceprint("ling");
        }
        show(N, 0, 0);
    }
    putchar('\n');
    return 0;
}
