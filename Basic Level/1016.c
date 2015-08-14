#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[11], da, b[11], db;
    int pa, pb, i;

    scanf("%s %c %s %c", a, &da, b, &db);
    for(i = 0, pa = 0; i < strlen(a); i++)
        if(a[i] == da)
            pa = pa * 10 + da - '0';
    for(i = 0, pb = 0; i < strlen(b); i++)
        if(b[i] == db)
            pb = pb * 10 + db - '0';
    printf("%d\n", pa + pb);
    
    return 0;
}
