#include "stdio.h"
int main()
{
    int n, b, a[110], i;
    scanf("%d%d", &n, &b);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= n - 1; i++)
    {
        if (a[i] % b == 0)
        {
            a[i] = 0;
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
            {
                if (i == 0)
                {
                    printf("%c", a[i]);
                }
                else
                {
                    printf(" %c", a[i]);
                }
            }
            else
            {
                if (i == 0)
                {
                    printf("%d", a[i]);
                }
                else
                {
                    printf(" %d", a[i]);
                }
            }
        }
    }
    return 0;
}