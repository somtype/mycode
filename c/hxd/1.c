#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 520
typedef struct {
    char name[100], sex;
    int age;
    char likes[10][100];
} INFO;
int main() {
    INFO oneguy;
    printf("请输入你的姓名：\n");
    scanf("%s", oneguy.name);
    getchar();
    printf("请输入你的性别：\n");
    char ch = getchar();
    if (ch != 'm' && ch != 'w') {
        //性别是否合法
        printf("error!\n");
        exit(1);
    }
    oneguy.sex = ch;
    printf("请输入你的年龄：\n");
    int temp;
    scanf("%d", &temp);
    if (temp > 60 || temp < 18) {
        //年龄是否合法
        printf("error!\n");
        exit(1);
    }
    oneguy.age = temp;
    printf("请输入你的爱好：\n");
    int n = 0;
    while (n < 4) {
        scanf("%s", oneguy.likes[n++]);
        char ch = getchar();
        if (ch == 10)
            //输入换行符则退出,空格则继续
            break;
    }
    //打印信息
    printf("%s->>", oneguy.name);
    printf("%c->>", oneguy.sex);
    printf("年龄%d->>", oneguy.age);
    printf("爱好");
    for (int i = 0; i < n; i++) {
        printf("%s ", oneguy.likes[i]);
    }
    printf("\n");
    return 0;
}