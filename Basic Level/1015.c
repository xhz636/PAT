#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int num;
    int mor;
    int abl;
} STU;

int cmp(const STU *a, const STU *b)
{
    int score1 = a->mor + a->abl;
    int score2 = b->mor + b->abl;
    if(score1 > score2)
        return -1;
    else if(score1 == score2 && a->mor > b->mor)
        return -1;
    else if(score1 == score2 && a->mor == b->mor && a->num < b->num)
        return -1;
    else
        return 1;
}

int main(void)
{
    int n, l, h, i, j, k, m[4] = {0, 0, 0, 0}, score1, score2, bigger;
    STU s[4][100000], t;

    scanf("%d %d %d", &n, &l, &h);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", &t.num, &t.mor, &t.abl);
        if(t.mor >= l && t.abl >= l)
        {
            if(t.mor >= h && t.abl >= h)
                s[0][m[0]++] = t;
            else if(t.mor >= h && t.abl < h)
                s[1][m[1]++] = t;
            else if(t.mor < h && t.abl < h && t.mor >= t.abl)
                s[2][m[2]++] = t;
            else
                s[3][m[3]++] = t;
        }
    }
    for(i = 0; i < 4; i++)
        qsort(s[i], m[i], sizeof(STU), cmp);
    printf("%d\n", m[0] + m[1] + m[2] + m[3]);
    for(i = 0; i < 4; i++)
        for(j = 0; j < m[i]; j++)
            printf("%d %d %d\n", s[i][j].num, s[i][j].mor, s[i][j].abl);

    return 0;
}
