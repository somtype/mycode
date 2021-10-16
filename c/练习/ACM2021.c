#include "stdio.h"
int main()
{
    int n, m, x, sum, i, j, a[6] = {100, 50, 10, 5, 2, 1};
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            break;
        }
        else
        {
            for (i = 1, sum = 0; i <= n; i++)
            {
                scanf("%d", &m);
                for (j = 0, x = 0; j <= 5; j++)
                {
                    x += m / a[j];
                    m %= a[j];
                }
                sum += x;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}