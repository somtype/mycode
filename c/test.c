#include <stdio.h>
int main() {
    int a[2] = {0, 1};
    int *p = a;
    printf("%d\n", *p++);
    printf("%d\n", *p);
}
int detectBits(int x) { return !(x & 2863311530 ^ 2863311530); }
