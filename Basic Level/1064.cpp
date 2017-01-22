#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    int* ID;
    int* S;
    cin >> N;
    ID = (int*)malloc(sizeof(int) * N);
    S = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        ID[i] = sum;
    }
    sort(ID, ID + N);
    S[0] = ID[0];
    int sc = 1;
    int A = ID[0];
    for (int i = 1; i < N; i++)
        if (ID[i] != A)
        {
            A = ID[i];
            S[sc++] = A;
        }
    cout << sc << endl;
    cout << S[0];
    for (int i = 1; i < sc; i++)
        cout << " " << S[i];
    cout << endl;
    return 0;
}
