#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef struct
{
    char plate[8];
    int time;
    int status;
} Record;
bool cmptime(Record a, Record b)
{
    return a.time < b.time;
}
bool cmpname(Record a, Record b)
{
    if (strcmp(a.plate, b.plate) != 0)
        return strcmp(a.plate, b.plate) < 0;
    else
        return a.time < b.time;
}
int main(void)
{
    int N, K;
    cin >> N >> K;
    Record R[N];
    for (int i = 0; i < N; i++)
    {
        int h, m, s;
        char io[4];
        scanf("%s %d:%d:%d %s", R[i].plate, &h, &m, &s, io);
        R[i].time = h * 3600 + m * 60 + s;
        R[i].status = io[0] == 'i';
    }
    int remove = 0;
    sort(R, R + N, cmpname);
    vector<string> Output;
    int maxtime = 0;
    int nowtime = 0;
    string nowname;
    for (int i = 1; i < N; i++)
    {
        if (strcmp(R[i - 1].plate, R[i].plate) == 0)
        {
            nowname = R[i].plate;
            if (R[i - 1].status == 1 && R[i].status == 0)
            {
                nowtime += R[i].time - R[i - 1].time;
                i++;
            }
            else if (R[i].status == 1)
            {
                R[i - 1].time = 3600 * 24;
                remove++;
            }
            else
            {
                R[i - 1].time = R[i].time = 3600 * 24;
                remove += 2;
                i++;
            }
        }
        else
        {
            if (nowtime > maxtime)
            {
                maxtime = nowtime;
                Output.clear();
                Output.push_back(nowname);
            }
            else if (nowtime == maxtime)
                Output.push_back(nowname);
            nowtime = 0;
            R[i - 1].time = 3600 * 24;
            remove++;
        }
        if (i == N - 1)
        {
            R[i].time = 3600 * 24;
            remove++;
        }
        else if (strcmp(R[i - 1].plate, R[i].plate) != 0)
        {
            if (nowtime > maxtime)
            {
                maxtime = nowtime;
                Output.clear();
                Output.push_back(nowname);
            }
            else if (nowtime == maxtime)
                Output.push_back(nowname);
            nowtime = 0;
        }
    }
    if (nowtime > maxtime)
    {
        maxtime = nowtime;
        Output.clear();
        Output.push_back(nowname);
    }
    else if (nowtime == maxtime)
        Output.push_back(nowname);
    sort(R, R + N, cmptime);
    N -= remove;
    int index = 0;
    int count = 0;
    for (int i = 0; i < K; i++)
    {
        int h, m, s, time;
        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 3600 + m * 60 + s;
        while (R[index].time <= time && index < N)
        {
            if (R[index].status == 1)
                count++;
            else
                count--;
            index++;
        }
        printf("%d\n", count);
    }
    for (int i = 0; i < Output.size(); i++)
    {
        if (i != 0)
            putchar(' ');
        cout << Output[i];
    }
    printf(" %02d:%02d:%02d\n", maxtime / 3600, maxtime / 60 % 60, maxtime % 60);
    return 0;
}
