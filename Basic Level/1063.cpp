#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    double max, a, b;
    max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        double c = sqrt(a * a + b * b);
        if (c > max)
            max = c;
    }
    printf("%.2f\n", max);
    return 0;
}
