#include "math.h"
#include "stdio.h"
int dod(int n)
{
    int k;
    if (n == 1)
    {
        k = 2;
    }
    else if (n == 2)
    {
        k = 3;
    }
    else
    {
        k = dod(n - 1) + dod(n - 2);
    }
    return k;
}
int main()
{

    int a[20] = {0};
    int n, m, num, i, j;
    scanf("%d", &n);
    m = dod(n);
    for (j = 0, num = 0; j <= pow(2, n) && num < m; j++)
    {
        for (int temp = j, i = 0; i <= n - 1; i++)
        {
            a[i] = temp % 2;
            temp /= 2;
        }
        for (i = 0; i <= n - 2; i++)
        {
            if (a[i] == 1 && a[i + 1] == 1)
            {
                break;
            }
        }
        if (i == n - 1)
        {
            num++;
            for (; i >= 0; i--)
            {
                printf("%d", a[i]);
            }
            printf("\n");
        }
    }
    printf("%d", m);
    return 0;
}