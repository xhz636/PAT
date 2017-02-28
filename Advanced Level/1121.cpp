#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M;
    int cp[100000];
    int come[100000];
    int dog[100000];
    for (int i = 0; i < 100000; i++)
    {
        cp[i] = -1;
        come[i] = 0;
        dog[i] = 0;
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int C, P;
        cin >> C >> P;
        cp[C] = P;
        cp[P] = C;
    }
    cin >> M;
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        int A;
        cin >> A;
        come[A] = 1;
        dog[A] = 1;
        count++;
        if (cp[A] != -1 && come[cp[A]])
        {
            dog[A] = 0;
            dog[cp[A]] = 0;
            count -= 2;
        }
    }
    cout << count << endl;
    int first = 1;
    for (int i = 0; i < 100000; i++)
        if (dog[i])
        {
            if (first)
            {
                first = 0;
                printf("%05d", i);
            }
            else 
            {
                printf(" %05d", i);
            }
        }
    return 0;
}
