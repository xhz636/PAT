#include<stdio.h>

struct data
{
    char name[6];
    int year;
    int month;
    int day;
} old, young, t;

int error(struct data p)
{
    if(p.year > 2014 || p.year == 2014 && p.month > 9 || p.year == 2014 && p.month == 9 && p.day > 6)
        return 1;
    if(p.year < 1814 || p.year == 1814 && p.month < 9 || p.year == 1814 && p.month == 9 && p.day < 6)
        return 1;
    return 0;
}

void check(struct data *a, struct data *b, struct data *c)
{
    if(a->year > c->year || a->year == c->year && a->month > c->month || a->year == c->year && a->month == c->month && a->day > c->day)
        *a = *c;
    if(b->year < c->year || b->year == c->year && b->month < c->month || b->year == c->year && b->month == c->month && b->day < c->day)
        *b = *c;
    return;
}

int main(void)
{
    int n, i, right, count;

    old.year = 2015;
    young.year = 1813;
    scanf("%d", &n);
    for(i = 0, count = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", t.name, &t.year, &t.month, &t.day);
        if(error(t))
            continue;
        count++;
        check(&old, &young, &t);
    }
    if(count)
        printf("%d %s %s\n", count, old.name, young.name);
    else
        printf("0\n");

    return 0;
}
