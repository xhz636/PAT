#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef struct
{
    int addr;
    int key;
    int next;
} Node;

bool cmp(Node a, Node b)
{
    return a.key < b.key;
}

int main(void)
{
    int N, head;
    cin >> N >> head;
    vector<Node> nodes;
    map<int, int> addrnum;
    for (int i = 0; i < N; i++)
    {
        Node temp;
        cin >> temp.addr >> temp.key >> temp.next;
        nodes.push_back(temp);
        addrnum[temp.addr] = i;
    }
    vector<Node> List;
    while (addrnum.count(head))
    {
        List.push_back(nodes[addrnum[head]]);
        head = nodes[addrnum[head]].next;
    }
    sort(List.begin(), List.end(), cmp);
    printf("%d", List.size());
    if (List.size() == 0)
    {
        printf(" -1\n");
        return 0;
    }
    printf(" %05d\n", List[0].addr);
    for (int i = 0; i < List.size(); i++)
    {
        printf("%05d %d", List[i].addr, List[i].key);
        if (i + 1 < List.size())
            printf(" %05d\n", List[i + 1].addr);
        else
            printf(" -1\n");
    }
    return 0;
}
