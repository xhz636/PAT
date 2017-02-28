#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    char num[11];
    sprintf(num, "%d", N);
    int len = strlen(num);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        char temp = num[i];
        num[i] = 0;
        int left, right;
        if (num[0] == 0)
            left = 0;
        else
            sscanf(num, "%d", &left);
        if (i == len - 1)
            right = 0;
        else
            sscanf(num + i + 1, "%d", &right);
        if (temp == '0')
        {
            int add = left;
            for (int j = i + 1; j < len; j++)
                add *= 10;
            sum += add;
        }
        else if (temp == '1')
        {
            int add = left;
            for (int j = i + 1; j < len; j++)
                add *= 10;
            add += right + 1;
            sum += add;
        }
        else
        {
            int add = left + 1;
            for (int j = i + 1; j < len; j++)
                add *= 10;
            sum += add;
        }
        num[i] = temp;
    }
    cout << sum << endl;
    return 0;
}
