#include "stdio.h"
int main()
{
    long long int a[35][35] = {0};
    int n, i, j;
    while (scanf("%d", &n) != EOF)
    {
        a[0][0] = a[1][0] = a[1][1] = 0;
        for (i = 0; i <= n - 1; i++)
        {
            for (j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                }
                printf("%lld ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}