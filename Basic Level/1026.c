#include<stdio.h>

int main(void)
{
    int c1, c2, c, h, m, s;

    scanf("%d %d", &c1, &c2);
    c = c2 - c1;
    s = c / 100 + (c % 100 >= 50 ? 1 : 0);
    h = s / 3600;
    m = s / 60 - h * 60;
    s = s % 60;
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
