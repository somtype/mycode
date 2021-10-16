#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double sum,n;
    int m,i;
    while(scanf("%lf%d",&n,&m)!=EOF)
    {
        for(i=2,sum=n;i<=m;i++)
        {
            n=sqrt(n);
            sum+=n;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}