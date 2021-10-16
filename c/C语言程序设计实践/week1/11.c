#include "stdio.h"
int step(int i, int j, int m, int n, int (*d)[1010]) {
    if (i >= m || j >= n) //越界
        return 0;
    if (i == m - 1 && j == n - 1) //到达目标
        return 1;
    if (d[i][j]) //当前位置已走过
        return d[i][j];
    else { //当前位置还未走过
        d[i][j] =
            step(i + 1, j, m, n, d) + step(i, j + 1, m, n, d); //向下走和向右走
        return d[i][j];
    }
}
int uniquePaths(int m, int n) {
    int d[1010][1010] = {0};
    int k = step(0, 0, m, n, d);
    return k;
}
int main() {
    int m, n;
    printf("input m and n:\n");
    scanf("%d%d", &m, &n);
    int k = uniquePaths(m, n);
    printf("result=%d\n", k);
    return 0;
}