#include "stdio.h"
int main() {
    char *p, *a = "I love China!";
    p = a;
    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }
    return 0;
}