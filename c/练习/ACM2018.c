#include "stdio.h"
int main()
{
    int n, i, a[100] = {1, 2, 3};
    for (i = 3; i <= 99; i++)
    {
        a[i] = a[i - 1] + a[i - 3];
    }
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        else
        {
            printf("%d\n", a[n - 1]);
        }
    }
    return 0;
}