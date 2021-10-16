#include <stdio.h>
#include <stdlib.h>
int main()
{
    double a;
    int f = 0, z = 0, l = 0, i, n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
        {
            scanf("%lf", &a);
            if (a > 0)
                z++;
            else if (a < 0)
                f++;
            else
                l++;
        }
        printf("%d %d %d\n", f, l, z);
        f = z = l = 0;
    }
    return 0;
}