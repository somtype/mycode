#include "stdio.h"
void in(int *p)
{
    int i;
    for (i = 0; i <= 9; i++, p++)
    {
        scanf("%d", p);
    }
}
void dod(int *p)
{
    int k, i, j;
    for (i = 0, k = i; i <= 9; i++)
    {
        if (p[i] > p[k])
        {
            k = i;
        }
    }
    int temp;
    temp = p[9];
    p[9] = p[k];
    p[k] = temp;
    for (i = 0, j = i; i <= 9; i++)
    {
        if (p[i] < p[j])
        {
            j = i;
        }
    }
    temp = p[0];
    p[0] = p[j];
    p[j] = temp;
}
void out(int *p)
{
    for (int i = 0; i <= 9; i++)
    {
        printf("%d", *p++);
    }
}
int main()
{
    int a[11];
    in(a);
    dod(a);
    out(a);
    return 0;
}