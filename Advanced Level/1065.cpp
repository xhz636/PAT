#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long int A, B, C, Sum;
        scanf("%lld %lld %lld", &A, &B, &C);
        Sum = A + B;
        printf("Case #%d: ", i);
        if (A > 0 && B > 0 && Sum <= 0
                || Sum > C && !(A < 0 && B < 0 && Sum >= 0))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
