#include <stdio.h>
int main() {
    int n = 100;
    scanf("%d", &n);
    printf("%d\n", detectBits(n));
    return 0;
}
int detectBits(int x) { return !(x & 2863311530 ^ 2863311530); }
