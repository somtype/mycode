#include "stdio.h"
void odo(int *p,int n,int m)
{
    int a[100];
    for (int i = 0, j = n - m; j <= n - 1;j++,i++)
    {
        a[i] = p[j];
    }
    for (int i = n-m-1; i >= 0;i--)
    {
        p[i + m] = p[i];
    }
    for (int i = 0; i <= m - 1;i++)
    {
        p[i] = a[i];
    }
}
int main()
{
    int n, m, a[1000];
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n - 1;i++)
    {
        scanf("%d", &a[i]);
    }
    odo(a, n, m);
    for (int i = 0; i <= n - 1;i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}