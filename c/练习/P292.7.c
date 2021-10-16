#include "stdio.h"
void odo(char *a, char *b, int m)
{
    int i;
    for (i = m - 1; a[i] != 0; i++)
    {
        *b++ = a[i];
    }
    *b = 0;
}
int main()
{
    char a[1000], b[1000];
    int m;
    gets(a);
    scanf("%d", &m);
    odo(a, b, m);
    puts(b);
    return 0;
}