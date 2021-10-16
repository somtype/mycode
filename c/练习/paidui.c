#include "stdio.h"
int main()
{
    void sort(int sup[], int n);
    int a[20010], i, m, n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for (i = 0; i <= (m + n - 1);i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, m + n);
        for (i = 0; (i <= m + n - 1);i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
void sort(int sup[], int n)
{
    int i,k,j;
    for (i = 0; i <= n - 2;i++)
    {
        k = i;
        for (j = i + 1; j <= n - 1;j++)
        {
            if(sup[j]>sup[k])
            {
                k = j;
            }
        }
        int temp;
        temp = sup[i];
        sup[i] = sup[k];
        sup[k] = temp;
    }
}