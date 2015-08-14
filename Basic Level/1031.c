#include<stdio.h>

int main(void)
{
    int n, i, j, z, count, flag;
    char s[100][19];

    scanf("%d\n", &n);
    for(i = 0, count = 0; i < n; flag = 0, i++)
    {
        gets(s[i]);
        for(j = 0; j < 17; j++)
            if(s[i][j] > '9' || s[i][j] < '0')
            {
                puts(s[i]);
                count++;
                flag = 1;
                break;
            }
        if(flag)
            continue;
        z = 0;
        z += (s[i][0] - '0') * 7;
        z += (s[i][1] - '0') * 9;
        z += (s[i][2] - '0') * 10;
        z += (s[i][3] - '0') * 5;
        z += (s[i][4] - '0') * 8;
        z += (s[i][5] - '0') * 4;
        z += (s[i][6] - '0') * 2;
        z += (s[i][7] - '0') * 1;
        z += (s[i][8] - '0') * 6;
        z += (s[i][9] - '0') * 3;
        z += (s[i][10] - '0') * 7;
        z += (s[i][11] - '0') * 9;
        z += (s[i][12] - '0') * 10;
        z += (s[i][13] - '0') * 5;
        z += (s[i][14] - '0') * 8;
        z += (s[i][15] - '0') * 4;
        z += (s[i][16] - '0') * 2;
        z %= 11;
        if(z >= 3 && 12 - z == s[i][17] - '0' || z == 0 && s[i][17] == '1' || z == 1 && s[i][17] == '0' || z == 2 && s[i][17] == 'X')
            continue;
        puts(s[i]);
        count++;
    }
    if(count == 0)
        printf("All passed\n");

    return 0;
}
