#include "stdio.h"
int main()
{
    int p, e, i, d, j, casenum = 1;
    while (1)
    {
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if (p == -1)
            break;
        else
        {
            for (j = d + 1; (j - p) % 23 != 0; ++j)
                ;
            for (; (j - e) % 28 != 0; j += 23)
                ;
            for (; (j - i) % 33 != 0; j += 23 * 28)
                ;
            printf("Case %d: the next triple peak occurs in %d days.\n", casenum, j - d);
            ++casenum;
        }
    }
    return 0;
}