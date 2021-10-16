#include "stdio.h"
int main()
{
    int b[1000], n, a, i,p=0;
    scanf("%d", &n);
    for (i = 0; i <= n - 1;i++)
    {
        scanf("%d", &b[i]);
    }
    scanf("%d", &a);
    for (i = 0; i <= n - 1;i++)
    {
        if(b[i]==a)
        {
            p = 1;
            break;
        }
    }
    if(p)
    {
        printf("%d\n", i + 1);
    }
    else
    {
        printf("-1");
    }
    return 0;
}