#include "math.h"
#include "stdio.h"
int main()
{
    int m, n, a[100][100], i, j, max, r, c;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (i = 0; i <= m - 1; i++)
        {
            for (j = 0; j <= n - 1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        max = a[0][0];
        for (i = 0; i <= m - 1; i++)
        {
            for (j = 0; j <= n - 1; j++)
            {
                if (abs(a[i][j]) > abs(max))
                {
                    max = a[i][j];
                    r = i + 1;
                    c = j + 1;
                }
            }
        }
        printf("%d %d %d\n", r, c, max);
    }
    return 0;
}