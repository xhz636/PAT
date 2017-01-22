#include<stdio.h>
#include<string.h>

int main(void)
{
    char A[101], B[101];
    char result[101];
    char pattern[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    int len_A, len_B, len_result;
    int num_A, num_B;
    int sub;
    int flag;

    scanf("%s %s", A, B);
    len_A = strlen(A);
    len_B = strlen(B);
    len_result = len_B > len_A ? len_B : len_A;
    result[len_result] = '\0';
    flag = 1;
    while(len_result)
    {
        len_A--;
        len_B--;
        len_result--;
        if(len_A >= 0)
            num_A = A[len_A] - '0';
        else
            num_A = 0;
        if(len_B >= 0)
            num_B = B[len_B] - '0';
        else
            num_B = 0;
        if(flag)
            result[len_result] = pattern[(num_A + num_B) % 13];
        else
        {
            sub = num_B - num_A;
            result[len_result] = sub >= 0 ? sub + '0' : sub + 10 + '0';
        }
        flag = !flag;
    }
    printf("%s\n", result);

    return 0;
}
