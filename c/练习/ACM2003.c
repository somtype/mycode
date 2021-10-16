#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y;
    while(scanf("%lf",&x)!=EOF)
    {
        y=fabs(x);
        printf("%.2f\n",y);
    }
    return 0;
}