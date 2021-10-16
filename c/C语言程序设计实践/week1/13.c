#include "stdio.h"
void rotate(int (*a)[1010], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) { //转置矩阵
        for (j = 0; j <= i; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for (i = 0; i < n; i++) { //沿竖直方向中轴线翻转
        for (j = 0, k = n - 1; j < n / 2; j++, k--) {
            int temp = a[i][j];
            a[i][j] = a[i][k];
            a[i][k] = temp;
        }
    }
}
int main() {
    int a[1010][1010] = {0};
    int n, i, j;
    printf("input n:\n");
    scanf("%d", &n);
    printf("input matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    rotate(a, n);
    printf("answer:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}