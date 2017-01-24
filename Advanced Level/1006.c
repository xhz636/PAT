#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char ID[16];
    int signin;
    int signout;
} RECORD;

int main(void)
{
    int m, hour, minute, second, i, signin_ID = 0, signout_ID = 0;
    RECORD* record;

    scanf("%d", &m);
    record = (RECORD*)malloc(sizeof(RECORD) * m);
    for(i = 0; i < m; i++)
    {
        scanf("%s", record[i].ID);
        scanf("%d:%d:%d", &hour, &minute, &second);
        record[i].signin = hour * 3600 + minute * 60 + second;
        if(record[signin_ID].signin > record[i].signin)
            signin_ID = i;
        scanf("%d:%d:%d", &hour, &minute, &second);
        record[i].signout = hour * 3600 + minute * 60 + second;
        if(record[signout_ID].signout < record[i].signout)
            signout_ID = i;
    }
    printf("%s %s\n", record[signin_ID].ID, record[signout_ID].ID);
    free(record);

    return 0;
}
