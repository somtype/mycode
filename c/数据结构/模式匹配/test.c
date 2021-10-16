#include "get_next.h"
#include "stdio.h"
#include "stdlib.h"
int KMP(char *s, char *t, int pos) {
    int next[100], sLen = strlen(s), tLen = strlen(t);
    get_next(t, next);
    int i = pos, j = 0;
    while (i < sLen && j < tLen) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else
            j = next[j];
    }
    if (j >= tLen)
        return i - tLen;
    else
        return 0;
}
int main() {
    char s[100], t[100];
    scanf("%s", s);
    getchar();
    scanf("%s", t);
    int ans = KMP(s, t, 0);
    printf("%d", ans + 1);
    return 0;
}