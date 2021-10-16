#include "stdio.h"
#include "string.h"
int main()
{
    char a[1001][11];
    int n;
    scanf("%d", &n);
    getchar();
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%s", a[i]);
        int j;
        if (i == 0)
        {
            continue;
        }
        else
        {
            for (j = 0; j <= i - 1; j++)
            {
                if (strcmp(a[i], a[j]) == 0)
                {
                    n--;
                    i--;
                }
            }
        }
    }
    printf("%d\n", n);
    return 0;
}