#include "math.h"
#include "stdio.h"
int main()
{
    int n, a[1010], i, j, max = 0, temp;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i <= n - 1; i++)
        {
            scanf("%d", &a[i]);
        }
        for (j = 0; j <= n - 1; j++)
        {
            for (i = 0; i <= n - 1; i++)
            {
                if (a[j] <= a[i])
                {
                    temp = a[j] * (abs(i - j));
                    if (temp > max)
                    {
                        max = temp;
                    }
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}