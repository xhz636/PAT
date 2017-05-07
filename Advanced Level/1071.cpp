#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    map<string, int> Count;
    char word[1048578], ch;
    int index = 0;
    do {
        ch = getchar();
        if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
            word[index++] = ch;
        else if (ch >= 'A' && ch <= 'Z')
            word[index++] = ch - 'A' + 'a';
        else
        {
            word[index] = '\0';
            if (index)
            {
                string str = word;
                Count[str]++;
                index = 0;
            }
        }
    } while (ch != '\n');
    map<string, int>::iterator it;
    string str;
    int max = 0;
    for (it = Count.begin(); it != Count.end(); it++)
        if (max < it->second)
        {
            str = it->first;
            max = it->second;
        }
    cout << str << " " << max << endl;
    return 0;
}
