#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN 1010
#define INF 0x3f3f3f3f
int main() {
    int m, total;
    int wt, win[20], mint,
        index; // wt:记录总共需要等待的时间  win[20]:记录窗口完成业务时的时刻
               // mint:记录空闲时间最长的窗口完成业务的时刻
    while (scanf("%d%d", &m, &total) != EOF) {
        memset(win, 0, sizeof(win));
        wt = 0;
        int k, t; // k:客户到的时间  t:办理业务的时间
        for (int i = 0; i < total; i++) {
            scanf("%d%d", &k, &t);
            mint = INF;
            for (int j = 0; j < m; j++) {
                //找到最早完成业务的窗口
                if (win[j] < mint) {
                    mint = win[j];
                    index = j;
                }
            }
            if (k < win[index]) {
                //客户到达时，窗口还没有完成业务
                wt += (win[index] - k);
                win[index] += t;
            } else {
                //客户到达时，窗口已完成业务
                win[index] = k + t;
            }
        }
        printf("%f\n", wt * 1.0 / total);
    }
    return 0;
}