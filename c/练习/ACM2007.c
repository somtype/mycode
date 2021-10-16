#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int a, b;
    int m, n, t;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (m > n)
        {
            t = m;
            m = n;
            n = t;
        }
        for (a = 0, b = 0; m <= n; m++)
        {
            if (m % 2 == 0)
                a = a + m * m;
            else
                b = b + m * m * m;
        }
        printf("%lld %lld\n", a, b);
    }
    return 0;
}