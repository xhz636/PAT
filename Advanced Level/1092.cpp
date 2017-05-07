#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char buy[1001];
    char need[1001];
    scanf("%s %s", buy, need);
    int buycnt[256];
    int needcnt[256];
    for (int i = 0; i < 256; i++)
        buycnt[i] = needcnt[i] = 0;
    for (int i = 0; i < strlen(buy); i++)
        buycnt[buy[i]]++;
    for (int i = 0; i < strlen(need); i++)
        needcnt[need[i]]++;
    int miss = 0;
    for (int i = 0; i < 256; i++)
    {
        if (needcnt[i] > buycnt[i])
            miss += needcnt[i] - buycnt[i];
    }
    if (miss)
        printf("No %d\n", miss);
    else
        printf("Yes %d\n", strlen(buy) - strlen(need));
    return 0;
}
