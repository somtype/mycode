#include "stdio.h"
int main()
{
    int n, m;
    int i, j;
    int a[100][100], b[100][100], c[100][100];
    scanf("%d%d", &n, &m);
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= m - 1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= m - 1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= m - 1; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= m - 1; j++)
        {
            if (j == 0)
            {
                printf("%d", c[i][j]);
            }
            else
            {
                printf(" %d", c[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}