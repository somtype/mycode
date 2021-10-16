#include "stdio.h"
int solution(int (*p)[1010], int m, int n) {
    struct Dir {
        int x, y;
    };
    struct Dir d[4] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //移动的方向，按顺序分别为右下左上
    int flag = 0, num = 0, i = 0, j = 0;
    int Rowdstns = m - 1, //行方向需要移动的步数
        Coldstns = n,     //列方向需要移动的步数
        Rowtempnum = 0,   //行方向移动的步数，
        Coltempnum = 0;   //列方向移动的步数
    while (num < m * n) {
        printf("%d ", p[i][j]);
        flag % 2 == 0 ? Coltempnum++ : Rowtempnum++;
        if (Coltempnum == Coldstns && Coldstns != 0) {
            Coltempnum = 0;
            flag++; //改变移动方向
            flag %= 4;
            Coldstns--; //需要移动的步数-1
        }
        if (Rowtempnum == Rowdstns && Rowdstns != 0) {
            Rowtempnum = 0;
            flag++; //改变移动方向
            flag %= 4;
            Rowdstns--; //需要移动的步数-1
        }
        num++;
        i += d[flag].x;
        j += d[flag].y;
    }
}
int main() {
    int a[1010][1010] = {0};
    int m, n, i, j;
    printf("input m and n:\n");
    scanf("%d%d", &m, &n);
    printf("input matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("answer:\n");
    solution(a, m, n);
    printf("\n");
    return 0;
}
