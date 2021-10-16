#include "stdio.h"
int main()
{
    int f1 = 1, f2 = 1, temp,i,n;
    while(scanf("%d",&n)!=EOF)
    {
        for (i = 3; i <= n; i++)
        {
            temp = f2;
            f2 = (f1 + f2) % 10007;
            f1 = temp;
        }
        printf("%d\n", f2);
    }
    return 0;
}