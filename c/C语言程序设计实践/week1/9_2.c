#include "stdio.h"
int main() {
    void fac(float *pk, int x);
    int m;
    float k;
    printf("input m:\n");
    scanf("%d", &m);
    fac(&k, m);
    printf("result=%f\n", k);
    return 0;
}
void fac(float *pk, int x) {
    *pk = x;
}