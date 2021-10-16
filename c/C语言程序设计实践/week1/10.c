#include "stdio.h"
int main() {
    char str1[1010] = {0}, str2[1010] = {0}, *s;
    char *stringcat(char *s1, char *s2);
    printf("请输入两组字符串：\n");
    scanf("%s%s", str1, str2);
    s = stringcat(str1, str2);
    printf("连接后：\n%s\n", s);
    return 0;
}
char *stringcat(char *s1, char *s2) {
    char *p1, *p2;
    p1 = s1;
    p2 = s2;
    while (*p1 != '\0')
        p1++;
    while (*p2 != '\0') {
        *p1 = *p2;
        p1++;
        p2++;
    }
    return s1;
}