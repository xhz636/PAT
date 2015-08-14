#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char should[81], input[81], broken[256] = {0};
    int i, j;

    gets(should);
    gets(input);
    for(i = 0, j = 0; i < strlen(should); i++)
    {
        if(should[i] == input[j])
        {
            j++;
            continue;
        }
        else if(broken[toupper(should[i])])
            continue;
        else
        {
            putchar(toupper(should[i]));
            broken[toupper(should[i])] = 1;
        }
    }
    putchar('\n');

    return 0;
}
