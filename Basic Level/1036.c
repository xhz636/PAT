#include<stdio.h>

int main(void)
{
    int n, i, j, height, width;
    char c;

    scanf("%d %c", &n, &c);
    width = n;
    if(width % 2 == 0)
        height = width / 2;
    else
        height = width / 2 + 1;
    for(i = 0; i < width; i++)
        putchar(c);
    putchar('\n');
    for(i = 0; i < height - 2; i++)
    {
        putchar(c);
        for(j = 0; j < width - 2; j++)
            putchar(' ');
        putchar(c);
        putchar('\n');
    }
    for(i = 0; i < width; i++)
        putchar(c);
    putchar('\n');

    return 0;
}
