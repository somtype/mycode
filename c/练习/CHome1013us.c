#include "stdio.h"
int main()
{
    long long int n, ans;
    while (scanf("%lld", &n) != EOF)
    {
        if (n % 2 != 0)
        {
            ans = n * (n - 1) * (n - 2);
        }
        else if (n % 3 != 0)
        {
            ans = n * (n - 1) * (n - 3);
        }
        else
        {
            ans = (n - 1) * (n - 2) * (n - 3);
        }
        printf("%lld\n", ans);
    }
    return 0;
}