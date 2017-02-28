#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXINT 0x7FFFFFFF
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int num[N];
    int pivot[N];
    int l[N], r[N];
    int count = 0;
    int lmax = 0, rmin = MAXINT;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        if (lmax < num[i])
        {
            l[i] = 1;
            lmax = num[i];
        }
        else
            l[i] = 0;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (rmin > num[i])
        {
            r[i] = 1;
            rmin = num[i];
        }
        else
            r[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (l[i] && r[i])
            pivot[count++] = num[i];
    }
    sort(pivot, pivot + count);
    cout << count << endl;
    if (count)
    {
        cout << pivot[0];
        for (int i = 1; i < count; i++)
            cout << " " << pivot[i];
    }
    cout << endl;
    return 0;
}
