#include "stdio.h"
#include "string.h"
int main()
{
    char a[10000], b[10000], c[100000];
    gets(a);
    gets(b);
    int la, lb, lc;
    int l, h, x = 0;
    la = strlen(a);
    lb = strlen(b);
    for (l = 0, h = la - 1; l <= h; l++, h--)
    {
        int temp;
        temp = a[l];
        a[l] = a[h] - 48;
        a[h] = temp - 48;
    }
    for (l = 0, h = lb - 1; l <= h; l++, h--)
    {
        int temp;
        temp = b[l];
        b[l] = b[h] - 48;
        b[h] = temp - 48;
    }
    int i, j;
    for (i = 0; i < la; i++)
    {
        for (j = 0; j < lb; j++)
        {
            c[i + j] += a[i] * b[j] + x;
            x = c[i + j] / 10;
            c[i + j] %= 10;
        }
        c[i + j] += x;
        x = 0;
    }
    lc = la + lb;
    for (i = lc - 1; i >= 0; i--)
    {
        if (c[i] != 0)
        {
            break;
        }
    }
    if (i == -1)
    {
        lc = 1;
    }
    else
    {
        lc = i + 1;
    }
    for (i = lc - 1; i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    return 0;
}