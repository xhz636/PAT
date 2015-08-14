#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char s[4][61];
    int day, hour, minute;
    int i, len[4], flag;
    char DAY[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    for(i = 0; i < 4; i++)
    {
        scanf(" %s", s[i]);
        len[i] = strlen(s[i]);
    }
    for(i = 0, flag = 0; i < (len[0] < len[1] ? len[0] : len[1]); i++)
    {
        if(s[0][i] == s[1][i])
        {
            if(flag == 0)
            {
                if(s[0][i] < 'A' || s[0][i] > 'G')
                    continue;
                day = s[0][i] - 'A';
                flag = 1;
            }
            else
            {
                if(isdigit(s[0][i]))
                    hour = s[0][i] - '0';
                else if(s[0][i] >= 'A' && s[0][i] <= 'N')
                    hour = s[0][i] - 'A' + 10;
                else
                    continue;
                break;
            }
        }
    }
    for(i = 0; i < (len[2] < len[3] ? len[2] : len[3]); i++)
    {
        if(s[2][i] == s[3][i] && isalpha(s[2][i]))
        {
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", DAY[day], hour, minute);

    return 0;
}
