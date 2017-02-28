#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> C[K + 1];
    for (int i = 0; i < N; i++)
    {
        char name[5];
        scanf("%s", name);
        int stu = ((name[0] - 'A') << 14)
                | ((name[1] - 'A') << 9)
                | ((name[2] - 'A') << 4)
                | (name[3] - '0');
        int count;
        scanf("%d", &count);
        for (int j = 0; j < count; j++)
        {
            int course;
            scanf("%d", &course);
            C[course].push_back(stu);
        }
    }
    for (int i = 1; i <= K; i++)
    {
        printf("%d %d\n", i, C[i].size());
        sort(C[i].begin(), C[i].end());
        for (int j = 0; j < C[i].size(); j++)
        {
            char name[5];
            name[0] = ((C[i][j] >> 14) & 0x1F) + 'A';
            name[1] = ((C[i][j] >> 9) & 0x1F) + 'A';
            name[2] = ((C[i][j] >> 4) & 0x1F) + 'A';
            name[3] = (C[i][j] & 0x0F) + '0';
            name[4] = '\0';
            printf("%s\n", name);
        }
    }
    return 0;
}
