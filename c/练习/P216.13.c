#include "stdio.h"
int main()
{
    double P(int n, double x);
    int    n;
    double x, ans;
    scanf("%d%lf", &n, &x);
    ans = P(n, x);
    printf("%f", ans);
    return 0;
}
double P(int n, double x)
{
    double y;
    if (n == 0)
    {
        y = 1;
    }
    else if (n == 1)
    {
        y = x;
    }
    else
    {
        y = ((2 * n - 1) * x - P(n - 1, x) - (n - 1) * P(n - 2, x)) / (n * 1.0);
    }
    return y;
}