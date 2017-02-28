#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ASCII[256];
int main(void)
{
    char S1[10001];
    char S2[10001];
    gets(S1);
    gets(S2);
    for (int i = 0; S2[i] != '\0'; i++)
        ASCII[S2[i]] = 1;
    for (int i = 0; S1[i] != '\0'; i++)
        if (ASCII[S1[i]])
            continue;
        else
            putchar(S1[i]);
    putchar('\n');
    return 0;
}
