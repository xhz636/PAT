#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void)
{
    char origin[84];
    char type[84];
    int broken[256];
    vector<int> detect;
    for (int i = 0; i < 256; i++)
        broken[i] = 0;
    scanf("%s %s", origin, type);
    int oi = 0;
    int ti = 0;
    while (origin[oi])
    {
        if (origin[oi] == type[ti])
        {
            oi++;
            ti++;
        }
        else
        {
            int ch = origin[oi];
            if (ch >= 'a' && ch <= 'z')
                ch = ch - 'a' + 'A';
            if (!broken[ch])
            {
                broken[ch] = 1;
                detect.push_back(ch);
            }
            oi++;
        }
    }
    for (int i = 0; i < detect.size(); i++)
        putchar(detect[i]);
    putchar('\n');
    return 0;
}
