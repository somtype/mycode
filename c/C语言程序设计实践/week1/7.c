#include "stdio.h"
int main() {
    int a[1010][1010] = {0};
    int(*p)[1010];
    int r, c;
    p = a;
    printf("请输入二维数组的行数与列数：\n");
    scanf("%d%d", &r, &c);
    printf("请输入二维数组：\n");
    for (int i = 0; i < r; i++) { //输入数组
        for (int j = 0; j < c; j++) {
            scanf("%d", *(p + i) + j);
        }
    }
    printf("输出二维数组：\n");
    for (int i = 0; i < r; i++) { //打印数组
        for (int j = 0; j < c; j++) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;
}