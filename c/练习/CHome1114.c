#include "stdio.h"
void sort(int *x,int n)
{
    int i, j, k;
    for (i = 0; i <= n - 2;i++)
    {
        k = i;
        for (j = i + 1; j <= n - 1;j++)
        {
            if(x[j]>x[k])
            {
                k = j;
            }
        }
        j = x[i];
        x[i] = x[k];
        x[k] = j;
    }
}
int main()
{
    int t, n, a[5000], b[5000];
    int i, j,k;
    scanf("%d", &t);
    for (i = 0; i <= t - 1;i++)
    {
        scanf("%d", &n);
        for (j = 0; j <= n - 1;j++)
        {
            scanf("%d", &a[j]);
        }
        for (j = 0; j <= n - 1;j++)
        {
            scanf("%d", &b[j]);
        }
        sort(a,n);
        sort(b, n);
        long long int ans = 0;
        for (k = 0; k <= n - 1;k++)
        {
            ans += a[k] * b[n - 1 - k];
        }
        printf("%lld\n", ans);
    }
        return 0;
}