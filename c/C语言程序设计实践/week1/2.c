#include "stdio.h"
int main() {
    int a[100][100] = {0};
    int n;
    printf("请输入矩阵阶数:\n");
    scanf("%d", &n);
    printf("请输入矩阵\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    printf("转置后：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}