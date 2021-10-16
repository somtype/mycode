#include "stdio.h"
int main()
{
    int l, k, i, a[100000], m, n, mid, sign = 0;
    scanf("%d%d", &l, &k);
    for (i = 0; i <= l - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    m = 0, n = l - 1;
    while (m <= n)
    {
        mid = (m + n) / 2;
        if (a[mid] == k)
        {
            printf("%d", mid + 1);
            sign = 1;
            break;
        }
        else if (a[mid] > k)
            n = mid - 1;
        else
            m = mid + 1;
    }
    if (sign == 0)
    {
        printf("Error!");
    }
    return 0;
}