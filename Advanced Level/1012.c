#include<stdio.h>

struct
{
    int id;
    int cpl;
    int math;
    int eng;
    int avg;
} stu[2000];
char course[4] = {'A', 'C', 'M', 'E'};

int main(void)
{
    int n, m;
    int i, j;
    int stu_id, index, rank[4];

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].cpl, &stu[i].math, &stu[i].eng);
        stu[i].avg = (stu[i].cpl + stu[i].math + stu[i].eng) / 3;
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d", &stu_id);
        for(j = 0; j < n; j++)
            if(stu_id == stu[j].id)
                break;
        if(j == n)
        {
            printf("N/A\n");
            continue;
        }
        index = j;
        for(j = 0, rank[0] = 1; j < n; j++)
            if(stu[j].avg > stu[index].avg)
                rank[0]++;
        for(j = 0, rank[1] = 1; j < n; j++)
            if(stu[j].cpl > stu[index].cpl)
                rank[1]++;
        for(j = 0, rank[2] = 1; j < n; j++)
            if(stu[j].math > stu[index].math)
                rank[2]++;
        for(j = 0, rank[3] = 1; j < n; j++)
            if(stu[j].eng > stu[index].eng)
                rank[3]++;
        for(j = 1, index = 0; j < 4; j++)
            if(rank[j] < rank[index])
                index = j;
        printf("%d %c\n", rank[index], course[index]);
    }

    return 0;
}
