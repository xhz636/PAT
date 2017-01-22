#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    vector<string> symbol[3];
    char sym[10];
    char c;
    string str;
    for (int i = 0; i < 3; i++)
    {
        c = getchar();
        int index = -1;
        while (c != '\n')
        {
            if (c == '[')
                index = 0;
            else if (c == ']')
            {
                sym[index] = '\0';
                index = -1;
                symbol[i].push_back(string(sym));
            }
            else if (index >= 0)
            {
                sym[index++] = c;
            }
            c = getchar();
        }
    }
    int K;
    int lh, le, m, re, rh;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> lh >> le >> m >> re >> rh;
        if (lh > symbol[0].size() || lh < 1
                || le > symbol[1].size() || le < 1
                || m > symbol[2].size() || m < 1
                || re > symbol[1].size() || re < 1
                || rh > symbol[0].size() || rh < 1)
        {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;
        }
        cout << symbol[0][lh - 1] << "(" << symbol[1][le - 1]
            << symbol[2][m - 1] << symbol[1][re - 1] << ")"
            << symbol[0][rh - 1] << endl;
    }
    return 0;
}
