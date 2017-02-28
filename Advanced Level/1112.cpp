#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int k;
    char str[1001];
    cin >> k;
    scanf("%s", str);
    int len = strlen(str);
    int key[256];
    for (int i = 0; i < 256; i++)
        key[i] = 1;
    int count = 0;
    char ch = '\0';
    char order[256];
    int index = 0;
    int detect[256];
    for (int i = 0; i < 256; i++)
        detect[i] = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ch)
        {
            if (count % k != 0 && count != 0)
                key[ch] = 0;
            ch = str[i];
            count = 1;
            if (!detect[ch])
            {
                order[index++] = ch;
                detect[ch] = 1;
            }
        }
        else
            count++;
    }
    if (count % k != 0 && count != 0)
        key[ch] = 0;
    for (int i = 0; i < index; i++)
    {
        if (key[order[i]] == 1)
            putchar(order[i]);
    }
    putchar('\n');
    char* p = str;
    while (*p)
    {
        putchar(*p);
        if (key[*p] != 1)
            p++;
        else
            p += k;
    }
    putchar('\n');
    return 0;
}
