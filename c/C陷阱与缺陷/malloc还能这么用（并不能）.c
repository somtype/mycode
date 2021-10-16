#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main() {
    char *r, s[20], t[20];
    //, *malloc();
    gets(s);
    gets(t);
    r = malloc(strlen(s) + strlen(t) + 1);
    return 0;
}