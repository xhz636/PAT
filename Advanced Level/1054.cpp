#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int color[256 * 256 * 256];
int main(void)
{
    int M, N;
    cin >> M >> N;
    int max = 0, dc;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int c;
            scanf("%d", &c);
            color[c]++;
            if (color[c] > max)
            {
                max = color[c];
                dc = c;
            }
        }
    }
    cout << dc << endl;
    return 0;
}
