#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Map[1011][1011];
int N, M, D;
int Visit[1011];
int Distance[1011];
double mindist, sumdist;
int station;
void Dijk(int index)
{
    for (int i = 1; i <= N; i++)
    {
        Visit[i] = 0;
        if (Map[index][i])
            Distance[i] = Map[index][i];
        else
            Distance[i] = D + 1;
    }
    for (int i = 1001; i <= 1000 + M; i++)
    {
        Visit[i] = 0;
        if(Map[index][i])
            Distance[i] = Map[index][i];
        else
            Distance[i] = D + 1;
    }
    while (1)
    {
        int next = index;
        Visit[next] = 1;
        for (int i = 1; i <= N; i++)
        {
            if (!Visit[i] &&
                    (next == index || Distance[i] < Distance[next]))
                next = i;
        }
        for (int i = 1001; i <= 1000 + M; i++)
        {
            if (!Visit[i] &&
                    (next == index || Distance[i] < Distance[next]))
                next = i;
        }
        Visit[next] = 1;
        if (Distance[next] > D || next == index)
            break;
        else
        {
            for (int i = 1; i <= N; i++)
            {
                if (Map[next][i]
                        && Distance[i] > Distance[next] + Map[next][i])
                    Distance[i] = Distance[next] + Map[next][i];
            }
            for (int i = 1001; i <= 1000 + M; i++)
            {
                if (Map[next][i]
                        && Distance[i] > Distance[next] + Map[next][i])
                    Distance[i] = Distance[next] + Map[next][i];
            }
        }
    }
    double min = D + 1, sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Distance[i] > D)
            return;
        else
        {
            if (min > Distance[i])
                min = Distance[i];
            sum += Distance[i];
        }
    }
    if (mindist < min || mindist == min && sumdist > sum)
    {
        mindist = min;
        sumdist = sum;
        station = index;
    }
}
int main(void)
{
    int K;
    cin >> N >> M >> K >> D;
    char num1[5], num2[5];
    int P1, P2, Dist;
    for (int i = 0; i < K; i++)
    {
        scanf("%s %s %d", num1, num2, &Dist);
        if (num1[0] == 'G')
        {
            sscanf(num1 + 1, "%d", &P1);
            P1 += 1000;
        }
        else
            sscanf(num1, "%d", &P1);
        if (num2[0] == 'G')
        {
            sscanf(num2 + 1, "%d", &P2);
            P2 += 1000;
        }
        else
            sscanf(num2, "%d", &P2);
        Map[P1][P2] = Dist;
        Map[P2][P1] = Dist;
    }
    for (int i = 1001; i <= 1000 + M; i++)
        Dijk(i);
    if (mindist)
        printf("G%d\n%.1f %.1f\n", station - 1000, mindist, sumdist / N);
    else
        printf("No Solution\n");
    return 0;
}
