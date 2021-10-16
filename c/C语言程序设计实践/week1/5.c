#include "stdio.h"
int main() {
    int num[1010] = {0};
    int n;
    printf("请输入数字个数：\n");
    scanf("%d", &n);
    printf("请输入数字：\n");
    for (int i = 0; i < n; i++) { //输入数组
        scanf("%d", num + i);
    }
    for (int i = 0; i < n / 2; i++) { //逆序重排
        int temp = *(num + i);
        *(num + i) = *(num + n - 1 - i);
        *(num + n - 1 - i) = temp;
    }
    printf("逆序重排：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(num + i));
    }
    return 0;
}