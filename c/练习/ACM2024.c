#include "ctype.h"
#include "stdio.h"
#include "string.h"
int main()
{
    char a[10000];
    int i, n, p, j;
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        for (j = 1; j <= n; j++)
        {
            gets(a);
            for (i = 0; i <= strlen(a) - 1; i++)
            {
                if (!isalpha(a[0]) && a[0] != '_')
                {
                    p = 0;
                    break;
                }
                else
                {
                    if (isalnum(a[i]) || a[i] == '_')
                    {
                        p = 1;
                    }
                    else
                    {
                        p = 0;
                        break;
                    }
                }
            }
            if (p)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }
    return 0;
}