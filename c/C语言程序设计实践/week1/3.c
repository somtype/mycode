#include "stdio.h"
int main() {
    int a[1010][1010] = {0};
    int found = 1, n;
    printf("请输入矩阵阶数:\n");
    scanf("%d", &n);
    printf("请输入矩阵:\n");
    for (int i = 0; i < n; i++) //输入矩阵
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++) //判断是否是对称矩阵
        for (int j = 0; j <= i; j++)
            if (a[i][j] != a[j][i])
                found = 0;
    if (found == 0) //输出结果
        printf("no\n");
    else
        printf("yes\n");
    return 0;
}