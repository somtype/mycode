#include "stdio.h"
int step(int i, int j, int *obstacleGrid, int *memory, int m, int n) {
    if (i >= m || j >= n) //越界
        return 0;
    if (*(obstacleGrid + i * 1010 + j) == 1) //遇到障碍物
        return 0;
    if (i == m - 1 && j == n - 1) //到达目的地
        return 1;
    if (*(memory + i * 1010 + j)) //当前位置已走过
        return *(memory + i * 1010 + j);
    else { //当前位置未走过
        *(memory + i * 1010 + j) =
            step(i + 1, j, obstacleGrid, memory, m, n) + //向下走
            step(i, j + 1, obstacleGrid, memory, m, n);  //向右走
        return *(memory + i * 1010 + j);
    }
}
int uniquePathsWithObstacles(int *obstacleGrid, int obstacleGridRowSize,
                             int obstacleGridColSize) {
    int k = 0, d[1010][1010] = {0}; // d[i][j]用于记录[i,j]位置的路径数
    k = step(0, 0, obstacleGrid, d[0], obstacleGridRowSize,
             obstacleGridColSize);
    return k;
}
int main() {
    int a[1010][1010] = {0};
    int m, n, i, j, k = 0;
    printf("input m and n:\n");
    scanf("%d%d", &m, &n);
    printf("input grid:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", a[0] + i * 1010 + j);
    k = uniquePathsWithObstacles(a[0], m, n);
    printf("共有%d条路径\n", k);
    return 0;
}