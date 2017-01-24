#include<stdio.h>

struct
{
    int father;
    int level;
    int havechild;
} member[100] = {0};
int leaf[100] = {0};

int main(void)
{
    int n, m, k, parent, child, maxlevel;
    int i, j;

    scanf("%d %d", &n, &m);
    member[1].level = maxlevel = 1;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &parent, &k);
        member[parent].havechild = 1;
        for(j = 0; j < k; j++)
        {
            scanf("%d", &child);
            member[child].father = parent;
        }
    }
    for(i = 2; i <= n; i++)
    {
        member[i].level = member[member[i].father].level + 1;
        if(member[i].level > maxlevel)
            maxlevel = member[i].level;
    }
    for(i = 1; i <= n; i++)
    {
        if(member[i].level != 0 && member[i].havechild == 0)
            leaf[member[i].level]++;
    }
    printf("%d", leaf[1]);
    for(i = 2; i <= maxlevel; i++)
        printf(" %d", leaf[i]);
    putchar('\n');

    return 0;
}
