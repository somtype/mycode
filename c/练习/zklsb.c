#include "stdio.h"
int main()
{
    int a, b, c;
    double y;
    scanf("%d%d%d", &a, &b, &c);
    y = (3.8 * (b * b + a * c)) / (6 * a);
    printf("%lf", y);
    return 0;
}