#include "stdio.h"
struct Date
{
    int y, m, d;
};
int main()
{
    int p[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i, ans;
    struct Date a;
    int isleap(int n);
    scanf("%d%d%d", &a.y, &a.m, &a.d);
    for (i = 0, ans = 0; i <= a.m - 2; i++)
    {
        ans += p[i];
    }
    ans += a.d;
    if (isleap(a.y) && a.m > 2)
    {
        ans++;
    }
    printf("%d", ans);
    return 0;
}
int isleap(int n)
{
    int z;
    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
    {
        z = 1;
    }
    else
    {
        z = 0;
    }
    return z;
}