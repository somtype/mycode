#include "stdio.h"
int main() {
    double a, x, ans = 0;
    int n, i;
    scanf("%d%lf", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a);
        double temp = 1;
        for (int j = 1; j <= i; j++) {
            temp *= x;
        }
        ans += a * temp;
    }
    printf("%lf", ans);
    return 0;
}