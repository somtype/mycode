#include "stdio.h"
int main()
{
    int a[10000], n, i, j, temp;
    long long int sum;
    scanf("%d", &n);
    for (i = 0, sum = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (j = 1; j <= n - 1; j++)
    {
        for (i = 0; i <= n - j - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    printf("%d\n%d\n%lld", a[n - 1], a[0], sum);
    return 0;
}