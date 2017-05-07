#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int N;
void format(char* str, int& P)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '.')
            P++;
        else
        {
            for (int j = i; j < strlen(str); j++)
                str[j] = str[j+1];
            break;
        }
    }
    while (str[0] == '0')
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = str[i + 1];
        P--;
    }
    for (int i = strlen(str); i < N; i++)
        str[i] = '0';
    str[N] = '\0';
}
int main(void)
{
    char A[110], B[110];
    scanf("%d %s %s", &N, A, B);
    int AP = 0, BP = 0;
    format(A, AP);
    format(B, BP);
    if (strcmp(A, B) == 0)
        printf("YES 0.%s*10^%d\n", A, AP);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", A, AP, B, BP);
    return 0;
}
