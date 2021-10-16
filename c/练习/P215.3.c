#include "stdio.h"
int main()
{
    int prm_num(int x);
    int a, p;
    scanf("%d", &a);
    p = prm_num(a);
    switch (p)
    {
    case 0:
        printf("NO");
        break;
    case 1:
        printf("YES");
        break;
    }
    printf("\n");
    return 0;
}
int prm_num(int x)
{
    int temp, i;
    for (i = 2; i <= x - 1; i++)
    {
        if (x % i == 0)
            break;
    }
    temp = i == x ? 1 : 0;
    return temp;
}