#include<stdio.h>

struct money
{
    int galleon;
    int sickle;
    int knut;
} p, a, r;

int main(void)
{
    long long int sump, suma, sumr;
    int flag;

    scanf("%d.%d.%d %d.%d.%d", &p.galleon, &p.sickle, &p.knut, &a.galleon, &a.sickle, &a.knut);
    sump = p.galleon * 17 *29 + p.sickle * 29 + p.knut;
    suma = a.galleon * 17 *29 + a.sickle * 29 + a.knut;
    sumr = suma - sump;
    if(sump > suma)
    {
        flag = 1;
        sumr = -sumr;
    }
    else
        flag = 0;
    r.galleon = (int)(sumr / 17 / 29);
    r.sickle = (int)((sumr - r.galleon * 17 * 29) / 29);
    r.knut = (int)(sumr % 29);
    if(flag)
        putchar('-');
    printf("%d.%d.%d\n", r.galleon, r.sickle, r.knut);

    return 0;
}
