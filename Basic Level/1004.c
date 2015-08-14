#include<stdio.h>

struct stu
{
    char name[11];
    char number[11];
    int score;
} max, min, temp;

int main(void)
{
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %s %d", temp.name, temp.number, &temp.score);
        if(i == 0)
        {
            max = temp;
            min = temp;
        }
        else if(temp.score > max.score)
            max = temp;
        else if(temp.score < min.score)
            min = temp;
    }
    printf("%s %s\n", max.name, max.number);
    printf("%s %s\n", min.name, min.number);

    return 0;
}
