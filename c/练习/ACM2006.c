#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,b,a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(b=1,m=0;m<n;m++)
        {
            scanf("%d",&a[m]);
            if(a[m]%2!=0) b*=a[m];
        }
        printf("%d\n",b);
    }
    return 0;
}