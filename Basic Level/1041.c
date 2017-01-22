#include<stdio.h>

typedef struct
{
    char id[15];
    int computer;
    int seat;
} MSG;

int main(void)
{
    MSG msg[1000];
    int N, M;
    int search;
    int i, j;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%s %d %d", msg[i].id, &msg[i].computer, &msg[i].seat);
    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d", &search);
        for(j = 0; j < N; j++)
            if(search == msg[j].computer)
            {
                printf("%s %d\n", msg[j].id, msg[j].seat);
                break;
            }
    }

    return 0;
}
