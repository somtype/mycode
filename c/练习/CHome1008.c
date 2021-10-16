#include "math.h"
#include "stdio.h"
int main()
{
    int n, m, i, j;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                printf("%c", 'A' + abs(i - j));
            }
            printf("\n");
        }
    }
    return 0;
}