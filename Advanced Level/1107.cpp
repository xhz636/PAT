#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int clustercnt = 0;
    int Pcluster[N];
    vector<int> Hcluster[N];
    for (int i = 0; i < N; i++)
    {
        int K, hobby;
        cin >> K;
        getchar();
        int index = -1;
        for (int j = 0; j < K; j++)
        {
            int found = 0;
            cin >> hobby;
            for (int x = 0; x < clustercnt; x++)
            {
                for (int y = 0; y < Hcluster[x].size(); y++)
                {
                    if (Hcluster[x][y] == hobby)
                    {
                        found = 1;
                        if (index == -1)
                            index = x;
                        else if (index != x)
                        {
                            int min = index < x ? index : x;
                            int max = index > x ? index : x;
                            Pcluster[min] = Pcluster[index] + Pcluster[x];
                            Hcluster[min].insert(Hcluster[min].end(), Hcluster[max].begin(), Hcluster[max].end());
                            index = min;
                            for (int k = max; k < clustercnt - 1; k++)
                            {
                                Pcluster[k] = Pcluster[k + 1];
                                Hcluster[k] = Hcluster[k + 1];
                            }
                            clustercnt--;
                        }
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (index == -1)
            {
                index = clustercnt++;
                Pcluster[index] = 0;
                Hcluster[index].push_back(hobby);
            }
            else if (!found)
                Hcluster[index].push_back(hobby);
        }
        Pcluster[index]++;
    }
    cout << clustercnt << endl;
    sort(Pcluster, Pcluster + clustercnt);
    cout << Pcluster[clustercnt - 1];
    for (int i = clustercnt - 2; i >= 0; i--)
        cout << " " << Pcluster[i];
    cout << endl;
    return 0;
}
