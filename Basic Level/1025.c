#include<stdio.h>

struct node
{
    int fore;
    int data;
    int next;
} list[100000];

int main(void)
{
    int head, n, k, i, t, index, count, flag;

    scanf("%d %d %d", &head, &n, &k);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &index);
        scanf("%d %d", &list[index].data, &list[index].next);
    }
    for(i = 0, index = head; i < n && index != -1; i++, index = list[index].next)
        list[list[index].next].fore = index;
    index = head;
    flag = 1;
    while(index != -1)
    {
        for(i = 0; i < k - 1 && index != -1; i++, index = list[index].next)
            continue;
        if(index != -1)
        {
            head = list[index].next;
            for(i = 0; i < k; i++, index = list[index].fore)
                if(flag)
                {
                    printf("%05d %d", index, list[index].data);
                    flag = 0;
                }
                else
                    printf(" %05d\n%05d %d", index, index, list[index].data);
            index = head;
        }
        else
            for(index = head; index != -1; index = list[index].next)
                if(flag)
                {
                    printf("%05d %d", index, list[index].data);
                    flag = 0;
                }
                else
                    printf(" %05d\n%05d %d", index, index, list[index].data);
    }
    printf(" -1\n");

    return 0;
}
