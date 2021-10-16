#include "stdio.h"
int max(int x, int y)
{
    int z;
    z = x > y ? x : y;
    return z;
}
int main()
{
    int n, i, ans = 0, temp, sum = 0;
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        if (sum < 0)
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}