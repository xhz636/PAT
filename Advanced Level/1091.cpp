#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int slice[60][1286][128];
int M, N, L, T;
int find(int x, int y, int z)
{
    queue<int> bfs;
    bfs.push((x << 18) | (y << 7) | z);
    slice[x][y][z] = 0;
    int count = 1;
    while (bfs.size())
    {
        int index = bfs.front();
        bfs.pop();
        x = index >> 18;
        y = (index >> 7) & 0x7FF;
        z = index & 0x7F;
        if (x - 1 >= 0 && slice[x - 1][y][z])
        {
            bfs.push(((x - 1) << 18) | (y << 7) | z);
            slice[x - 1][y][z] = 0;
            count++;
        }
        if (x + 1 < L && slice[x + 1][y][z])
        {
            bfs.push(((x + 1) << 18) | (y << 7) | z);
            slice[x + 1][y][z] = 0;
            count++;
        }
        if (y - 1 >= 0 && slice[x][y - 1][z])
        {
            bfs.push((x << 18) | ((y - 1) << 7) | z);
            slice[x][y - 1][z] = 0;
            count++;
        }
        if (y + 1 < M && slice[x][y + 1][z])
        {
            bfs.push((x << 18) | ((y + 1) << 7) | z);
            slice[x][y + 1][z] = 0;
            count++;
        }
        if (z - 1 >= 0 && slice[x][y][z - 1])
        {
            bfs.push((x << 18) | (y << 7) | (z - 1));
            slice[x][y][z - 1] = 0;
            count++;
        }
        if (z + 1 < N && slice[x][y][z + 1])
        {
            bfs.push((x << 18) | (y << 7) | (z + 1));
            slice[x][y][z + 1] = 0;
            count++;
        }
    }
    return count;
}
int main(void)
{
    cin >> M >> N >> L >> T;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &slice[i][j][k]);
    int total = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                if (slice[i][j][k])
                {
                    int volume = find(i, j, k);
                    if (volume >= T)
                        total += volume;
                }
    cout << total << endl;
    return 0;
}
