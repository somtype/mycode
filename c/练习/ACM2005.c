#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,m,d,all,n,leap;
    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        if((y%4==0&&y%100!=0)||y%400==0) leap=1;
        else leap=0;
        if(m==1||m==2) all=(m-1)*31+d;
        else
        {
            if(m<=8)
            {
                n=(m-1)/2.0+0.5;
                all=n*31+(m-1-n)*30+d;
            }
            else
            {
                n=(m-8)/2.0+0.5;
                all=214+n*31+(m-8-n)*30+d;
            }
            if(leap) all=all-1;
            else all=all-2;
        }
        printf("%d\n",all);
    }
    return 0;
}