#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    int Q[100][3];
    int E[100];
    int ans[5] = {0x01, 0x02, 0x04, 0x08, 0x10};
    for (int i = 0; i < M; i++)
    {
        E[i] = 0;
        int num;
        cin >> Q[i][0] >> Q[i][1] >> num;
        Q[i][2] = 0;
        for (int j = 0; j < num; j++)
        {
            char c;
            scanf(" %c", &c);
            Q[i][2] |= ans[c - 'a'];
        }
    }
    getchar();
    for (int i = 0; i < N; i++)
    {
        int score = 0;
        char c = getchar();
        int index = 0;
        while(c != '\n')
        {
            int n, a;
            if (c == '(')
            {
                cin >> n;
                int sa = 0;
                for (int j = 0; j < n; j++)
                {
                    char c;
                    scanf(" %c", &c);
                    sa |= ans[c - 'a'];
                }
                if (Q[index][2] == sa)
                {
                    score += Q[index][0];
                }
                else
                {
                    E[index]++;
                }
                index++;
            }
            c = getchar();
        }
        cout << score << endl;
    }
    int max = 0;
    for (int i = 0; i < M; i++)
        if (max < E[i])
            max = E[i];
    if (max)
    {
        cout << max;
        for (int i = 0; i < M; i++)
            if (E[i] == max)
                cout << " " << (i + 1);
    }
    else
    {
        cout << "Too simple";
    }
    cout << endl;
    return 0;
}
