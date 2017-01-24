#include<stdio.h>

int main(void)
{
    int i, j;
    double odd[3][3];
    int max_index[3];

    for(i = 0; i < 3; i++)
        for(j = 0, max_index[i] = 0; j < 3; j++)
        {
            scanf("%lf", &odd[i][j]);
            if(odd[i][max_index[i]] < odd[i][j])
                max_index[i] = j;
        }
    for(i = 0; i < 3; i++)
        switch(max_index[i])
        {
            case 0 : printf("W "); break;
            case 1 : printf("T "); break;
            case 2 : printf("L "); break;
        }
    printf("%.2f\n", (odd[0][max_index[0]] * odd[1][max_index[1]] * odd[2][max_index[2]] * 0.65 - 1) * 2);

    return 0;
}
