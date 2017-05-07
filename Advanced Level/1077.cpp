#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    char line[N][256];
    char kuchiguse[256];
    int klen = 0;
    int index[N];
    int notexist = 0;
    getchar();
    for (int i = 0; i < N; i++)
    {
        gets(line[i]);
        index[i] = strlen(line[i]) - 1;
        if (index[i] < 0)
            notexist = 1;
    }
    if (notexist)
        cout << "nai" << endl;
    else
    {
        int done = 0;
        while (!done)
        {
            char ch = line[0][index[0]--];
            if (index[0] < 0)
                done = 1;
            int same = 1;
            for (int i = 1; i < N; i++)
            {
                if (line[i][index[i]--] != ch)
                    same = 0;
                if (index[i] < 0)
                    done = 1;
                if (!same)
                    break;
            }
            if (same)
                kuchiguse[klen++] = ch;
            else
                break;
        }
        if (klen)
        {
            while (klen > 0)
                putchar(kuchiguse[--klen]);
            putchar('\n');
        }
        else
            cout << "nai" << endl;
    }
    return 0;
}
