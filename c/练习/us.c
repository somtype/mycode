#include "stdio.h"
#include "string.h"
int main()
{
    int  n;
    char t[ 100001 ], s[ 100001 ];
    scanf("%d", &n);
    getchar();
    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%s", t);
        scanf("%s", s);
        int sum, j;
        for (sum = 0, j = 0; j <= strlen(t) - strlen(s); j++)
        {
            int k, l;
            for (k = j, l = 0; k <= j + strlen(s) - 1; k++, l++)
            {
                if (t[ k ] != s[ l ])
                    break;
            }
            if (k == j + strlen(s))
            {
                sum++;
                j += strlen(s) - 1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}