#include<stdio.h>
#include<string.h>

void check(char *s)
{
    int i, p, t, a[3];
    for(i = 0, p = -1, t = -1; i < strlen(s); i++)
        if(s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
        {
            puts("NO");
            return;
        }
        else if(s[i] == 'P')
        {
            if(p == -1)
                p = i;
            else
            {
                puts("NO");
                return;
            }
        }
        else if(s[i] == 'T')
        {
            if(t == -1)
                t = i;
            else
            {
                puts("NO");
                return;
            }
        }
    a[0] = p;
    a[1] = strlen(s) - t - 1;
    a[2] = strlen(s) - a[0] - a[1] - 2;
    if(a[2] == 0)
        puts("NO");
    else if(a[1] == 0 && a[0] == 0)
        puts("YES");
    else if(a[0] != 0 && a[1] % a[0] == 0 && a[1] / a[0] == a[2])
        puts("YES");
    else
        puts("NO");

    return;
}

int main(void)
{
    char s[101];
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf(" %s", s);
        check(s);
    }

    return 0;
}
