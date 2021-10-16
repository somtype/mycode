#include "stdio.h"
int main()
{
    int divisor(int x, int y);
    int multiple(int x, int y);
    int a, b, ans1, ans2;
    scanf("%d%d", &a, &b);
    ans1 = divisor(a, b);
    ans2 = multiple(a, b);
    printf("最大公约数=%d，最小公倍数=%d", ans1, ans2);
    return 0;
}
int divisor(int x, int y)
{
    int temp;
    while (x % y != 0)
    {
        temp = y;
        y = x % y;
        x = temp;
    }
    return y;
}
int multiple(int x, int y)
{
    int temp;
    temp = divisor(x, y);
    temp = x * y / temp;
    return temp;
}