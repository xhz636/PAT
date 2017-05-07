#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int S[N];
    int Visit[N];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        Visit[i] = 0;
    }
    int count = 0;
    int circle = 0;
    for (int i = 0; i < N; i++)
    {
        if (Visit[i])
            continue;
        else
        {
            Visit[i] = 1;
            if (S[i] == i)
                continue;
            else
            {
                int index = S[i];
                count++;
                while (!Visit[index])
                {
                    Visit[index] = 1;
                    index = S[index];
                    count++;
                }
                circle++;
            }
        }
    }
    if (circle == 0)
        cout << "0" << endl;
    else
    {
        if (S[0] == 0)
            count++;
        else
            count--;
        count += circle - 1;
        cout << count << endl;
    }
    return 0;
}
