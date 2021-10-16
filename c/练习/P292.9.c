#include "stdio.h"
void odo(int a[][3])
{
    int b[3][3];
    int i, j;
    for (i = 0; i <= 2;i++)
    {
        for (j = 0; j <= 2;j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (i = 0; i <= 2;i++)
    {
        for (j = 0; j <= 2;j++)
        {
            a[i][j] = b[j][i];
        }
    }
}
int main()
{
    int a[3][3];
    int i, j;
    for (i = 0; i <= 2;i++)
    {
        for (j = 0; j <= 2;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    odo(a);
    for (i = 0; i <= 2;i++)
    {
        for (j = 0; j <= 2;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}