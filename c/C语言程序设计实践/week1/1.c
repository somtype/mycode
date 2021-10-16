//冒泡法排序
#include "stdio.h"
int main() {
    int a[5] = {0};
    printf("请输入五个数字：\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("排序后：\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}