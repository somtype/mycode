#include "string.h"
void get_next(char *s, int *next) {
    int sLen = strlen(s), i = 0, j = -1;
    next[0] = -1;
    while (i < sLen) {
        if (j == -1 || s[i] == s[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}