#include "math.h"
#include "stdio.h"
int main()
{
    int n, a[110], i, j, temp;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        else
        {
            for (i = 0; i <= n - 1; i++)
            {
                scanf("%d", &a[i]);
            }
            for (i = 1; i <= n - 1; i++)
            {
                for (j = 0; j <= n - i - 1; j++)
                {
                    if (abs(a[j]) < abs(a[j + 1]))
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
            for (i = 0, temp = 0; i <= n - 1; i++)
            {
                if (temp == 0)
                {
                    printf("%d", a[i]);
                    temp++;
                }
                else
                {
                    printf(" %d", a[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}