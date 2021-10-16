#include "stdio.h"
int main() {
    int num[1010] = {0};
    int n;
    int *p, *fp;
    p = fp = NULL;
    printf("请输入数字个数：\n");
    scanf("%d", &n);
    printf("请输入数字：\n");
    for (p = num; p < num + n; p++) { //输入数组
        scanf("%d", p);
    }
    for (p = num, fp = num + n - 1; p < num + n / 2; p++, fp--) { //逆序重排
        int temp = *p;
        *p = *fp;
        *fp = temp;
    }
    printf("逆序重排：\n");
    for (p = num; p < num + n; p++) { //打印数组
        printf("%d ", *p);
    }
    return 0;
}