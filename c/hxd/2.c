#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 520
int main() {
    int num[MAXN];
    printf("输入十个数字:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    int temp = 0;
    for (int i = 0; i < 10; i++) {
        if (num[i] % 2 != 0) {
            printf("%d ", num[i]);
            temp++;
            if ((temp %= 3) == 0)
                printf("\n");
        }
    }
    return 0;
}