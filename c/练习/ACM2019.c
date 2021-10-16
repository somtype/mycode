#include "stdio.h"
int main()
{
    int n, m, i, a[110], p;
    while (1)
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
        else
        {
            for (i = 0; i <= n - 1; i++)
            {
                scanf("%d", &a[i]);
            }
            for (i = n - 1; i >= 0; i--)
            {
                if (a[i] >= m)
                {
                    a[i + 1] = a[i];
                }
                else
                {
                    a[i + 1] = m;
                    break;
                }
            }
            for (i = 0, p = 0; i <= n; i++)
            {
                if (p == 0)
                {
                    printf("%d", a[i]);
                    p++;
                }
                else
                {
                    printf(" %d", a[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}