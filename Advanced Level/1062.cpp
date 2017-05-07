#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
    int ID;
    int Virtue;
    int Talent;
} People;
vector<People> Rank;
int L, H;
int gettype(People a)
{
    if (a.Virtue >= H && a.Talent >= H)
        return 4;
    else if (a.Virtue >= H && a.Talent < H)
        return 3;
    else if (a.Virtue < H && a.Talent < H && a.Virtue >= a.Talent)
        return 2;
    else
        return 1;
}
bool cmp(People a, People b)
{
    if (gettype(a) == gettype(b))
    {
        if (a.Virtue + a.Talent != b.Virtue + b.Talent)
            return a.Virtue + a.Talent > b.Virtue + b.Talent;
        else if (a.Virtue != b.Virtue)
            return a.Virtue > b.Virtue;
        else
            return a.ID < b.ID;
    }
    else
        return gettype(a) > gettype(b);
}
int main(void)
{
    int N;
    cin >> N >> L >> H;
    for (int i = 0; i < N; i++)
    {
        People temp;
        scanf("%d %d %d", &temp.ID, &temp.Virtue, &temp.Talent);
        if (temp.Virtue >= L && temp.Talent >= L)
            Rank.push_back(temp);
    }
    sort(Rank.begin(), Rank.end(), cmp);
    cout << Rank.size() << endl;
    for (int i = 0; i < Rank.size(); i++)
        printf("%08d %d %d\n", Rank[i].ID, Rank[i].Virtue, Rank[i].Talent);
    return 0;
}
