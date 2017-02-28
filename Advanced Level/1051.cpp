#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int main(void)
{
    int M, N, K;
    cin >> M >> N >> K;
    int num[N];
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> num[N - j - 1];
        int flag = 1;
        stack<int> S;
        int check[N + 1];
        int checkcnt = N;
        for (int j = 0; j < N; j++)
        {
            if (S.size() == 0 || S.top() < num[j])
                S.push(num[j]);
            else if (S.top() > num[j])
            {
                while (S.size() > 0 && S.top() > num[j])
                {
                    check[checkcnt--] = S.top();
                    S.pop();
                }
                S.push(num[j]);
            }
            if (S.size() > M)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            while (S.size())
            {
                check[checkcnt--] = S.top();
                S.pop();
            }
            for (int j = 1; j <= N; j++)
                if (check[j] != j)
                {
                    flag = 0;
                    break;
                }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
