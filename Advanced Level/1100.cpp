#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[13] = {"xxx", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    map<string, int> mtoe;
    map<int, string> etom;
    for (int i = 0; i < 13; i++)
    {
        mtoe[low[i]] = i;
        mtoe[high[i]] = i * 13;
        etom[i] = low[i];
        if (i != 0)
            etom[i * 13] = high[i];
    }
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        char line[10];
        gets(line);
        int index = 0;
        int num;
        char ml[5], mh[5];
        if (line[0] >= '0' && line[0] <= '9')
        {
            sscanf(line, "%d", &num);
            if (num >= 13)
            {
                cout << etom[num / 13 * 13];
                if (num % 13 != 0)
                    cout << " " << etom[num % 13];
                putchar('\n');
            }
            else
                cout << etom[num] << endl;
        }
        else if (line[3] == ' ')
        {
            sscanf(line, "%s %s", mh, ml);
            num = mtoe[mh] + mtoe[ml];
            printf("%d\n", num);
        }
        else
        {
            sscanf(line, "%s", ml);
            num = mtoe[ml];
            printf("%d\n", num);
        }
    }
    return 0;
}
