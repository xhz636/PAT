#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    long long int A, B;
    long long int G, S, K;
    scanf("%lld.%lld.%lld", &G, &S, &K);
    A = G * 17 * 29 + S * 29 + K;
    scanf("%lld.%lld.%lld", &G, &S, &K);
    B = G * 17 * 29 + S * 29 + K;
    long long int C = A + B;
    G = C / 29 / 17;
    S = C / 29 % 17;
    K = C % 29;
    printf("%lld.%lld.%lld\n", G, S, K);
    return 0;
}
