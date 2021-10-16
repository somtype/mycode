#include "stdio.h"
int main() {
    int a, b, c1, c2, c3;
    a = 10, b = 5;
    c1 = a---b;
    c2 = a-- - b;
    c3 = a - --b;
    printf("c1=%d,c2=%d,c3=%d\n", c1, c2, c3);
    // c1与c2等价, c3
    return 0;
}