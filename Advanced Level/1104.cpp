#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    double S[N];
    for (int i = 0; i < N; i++)
        scanf("%lf", &S[i]);
    double sum = 0;
    for (int i = 0; i < N; i++)
        sum += S[i] * (N - i) * (i + 1);
    printf("%.2f\n", sum);
    return 0;
}
