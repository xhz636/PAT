#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char line[100001];
    scanf("%s", line);
    int count = 0;
    int A = 0, T = 0;
    for (int i = strlen(line) - 1; i >= 0; i--)
    {
        if (line[i] == 'T')
            T++;
        else if (line[i] == 'A')
        {
            A += T;
            A %= 1000000007;
        }
        else if (line[i] == 'P')
        {
            count += A;
            count %= 1000000007;
        }
    }
    cout << count << endl;
    return 0;
}
