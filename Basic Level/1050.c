#include<stdio.h>
#include<stdlib.h>

#define Up 1
#define Down 2
#define Left 3
#define Right 4

int matrix[10000][10000];

int cmp(const void * a, const void * b)
{
    return *(int *)b - *(int *)a;
}


int main(void)
{
    int N, i, j;
    int x, y;
    int num[10000];
    int m, n;
    int direction;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &num[i]);
    qsort(num, N, sizeof(int), cmp);
    m = N;
    n = 1;
    for(i = N - 1; i >= N / m; i--)
        if(N % i == 0 && i > n)
        {
            m = i;
            n = N / i;
        }
    x = 0;
    y = 0;
    direction = Right;
    for(i = 0; i < N; i++)
    {
        matrix[y][x] = num[i];
        switch(direction)
        {
            case Up : if(y > 0 && matrix[y - 1][x] == 0)
                          y -= 1;
                      else
                      {
                          x += 1;
                          direction = Right;
                      }
                      break;
            case Down : if(y < m - 1 && matrix[y + 1][x] == 0)
                            y += 1;
                        else
                        {
                            x -= 1;
                            direction = Left;
                        }
                        break;
            case Left : if(x > 0 && matrix[y][x - 1] == 0)
                            x -= 1;
                        else
                        {
                            y -= 1;
                            direction = Up;
                        }
                        break;
            case Right : if(x < n - 1 && matrix[y][x + 1] == 0)
                             x += 1;
                         else
                         {
                             y += 1;
                             direction = Down;
                         }
                         break;
        }
    }
    for(i = 0; i < m; i++)
    {
        printf("%d", matrix[i][0]);
        for(j = 1; j < n; j++)
            printf(" %d", matrix[i][j]);
        putchar('\n');
    }

    return 0;
}
