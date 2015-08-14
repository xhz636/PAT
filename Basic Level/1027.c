#include<stdio.h>
#include<math.h>

int main(void)
{
    int n, i, t, j;
    char c;

    scanf("%d %c", &n, &c);
    t = (int)sqrt((n + 1) / 2);
    for(i = 0; i < 2 * t - 1; i++)
    {
        for(j = 0; j < t - 1 - abs(t - 1 - i); j++)
            putchar(' ');
        for(j = 0; j < 2 * abs(t - 1 - i) + 1; j++)
        {
            putchar(c);
            n--;
        }
        putchar('\n');
    }
    printf("%d\n", n);

    return 0;
}
