#include "stdio.h"
int main()
{
    int a[5], i, j, n;
    for (i = 0; i <= 31; i++)
    {
        n = i;
        for (j = 0; j <= 4; j++)
        {
            a[j] = n % 2;
            n /= 2;
        }
        for (j = 4; j >= 0;j--)
        {
            printf("%d", a[j]);
        }
        printf("\n");
    }
    return 0;
}