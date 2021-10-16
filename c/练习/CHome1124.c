#include "stdio.h"
int main()
{
    int n, m, a[1010];
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= m - 1; i++)
    {
        scanf("%d%d", &x, &y);
        int temp = a[x - 1];
        a[x - 1] = a[y - 1];
        a[y - 1] = temp;
    }
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}