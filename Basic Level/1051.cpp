#include <iostream>
#include <cstdio>
#include <cmath>
#include <cfloat>
using namespace std;

int main(void)
{
    double R1, P1, R2, P2, R, P, A, B;
    cin >> R1 >> P1 >> R2 >> P2;
    R = R1 * R2;
    P = P1 + P2;
    A = R * cos(P);
    B = R * sin(P);
    if (A <= 0.005 && A >= -0.005)
        A = 0;
    if (B <= 0.005 && B >= -0.005)
        B = 0;
    printf("%.2f%+.2fi\n", A, B);
    return 0;
}
