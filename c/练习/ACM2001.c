#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1,y1,x2,y2,d;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2f\n",d);
    }
    return 0;
}