#include "stdio.h"
int main() {
    int fac(int x);
    int m;
    float k;
    printf("input m:\n");
    scanf("%d", &m);
    k = fac(m);
    printf("result=%f\n", k);
    return 0;
}
int fac(int x) {
    return x;
}