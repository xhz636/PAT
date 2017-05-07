#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char str[4][64];
    char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for (int i = 0; i < 4; i++)
        scanf("%s", str[i]);
    int match = 0;
    for (int i = 0; i < strlen(str[0]) && i < strlen(str[1]); i++)
        if (str[0][i] == str[1][i] &&
                (match != 0 || str[0][i] >= 'A' && str[0][i] <= 'G'))
        {
            if (match == 0)
            {
                printf("%s ", day[(str[0][i] - 'A' + 1) % 7]);
            }
            else
            {
                int num = -1;
                if (str[0][i] >= '0' && str[0][i] <= '9')
                    num = str[0][i] - '0';
                else if (str[0][i] >= 'A' && str[0][i] <= 'N')
                    num = str[0][i] - 'A' + 10;
                if (num != -1)
                    printf("%02d:", num);
                else
                    match--;
            }
            match++;
            if (match == 2)
                break;
        }
    for (int i = 0; i < strlen(str[2]) && i < strlen(str[3]); i++)
        if (str[2][i] == str[3][i] &&
                (str[2][i] >= 'a' && str[2][i] <= 'z'
                 || str[2][i] >= 'A' && str[2][i] <= 'Z'))
        {
            printf("%02d\n", i);
            break;
        }
    return 0;
}
