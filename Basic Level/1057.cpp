#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    char c;
    int sum = 0;
    c = getchar();
    while (c != '\n')
    {
        if (c >= 'A' && c <= 'Z')
            sum += c - 'A' + 1;
        else if (c >= 'a' && c <= 'z')
            sum += c - 'a' + 1;
        c = getchar();
    }
    int one = 0, zero = 0;
    while (sum)
    {
        if (sum % 2 == 0)
            zero++;
        else
            one++;
        sum /= 2;
    }
    cout << zero << " " << one << endl;
    return 0;
}
