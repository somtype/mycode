#include "stdio.h"
int main() {
    int num[1010] = {0};
    int n, max;
    int *p;
    printf("请输入数字个数：\n");
    scanf("%d", &n);
    printf("请输入数字：\n");
    for (p = num; p < num + n; p++) {
        scanf("%d", p);
    }
    for (p = num, max = *p; p < num + n; p++) //找出最大的数
        if (*p > max)
            max = *p;
    for (p = num; p < num + n; p++) { //确定最大数的位置并交换
        if (*p == max) {
            int temp = *p;
            *p = *(num + n - 1);
            *(num + n - 1) = temp;
            break;
        }
    }
    printf("处理后：\n");
    for (p = num; p < num + n; p++) //打印数组
        printf("%d ", *p);
    printf("\n");
    return 0;
}