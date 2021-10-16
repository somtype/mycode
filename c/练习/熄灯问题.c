#include "stdio.h"
#include "string.h"
int light[7][8], ans[7][8], lighttemp[7][8];
int iswholelineoff(int i)
{
    int j, flag = 1;
    for (j = 1; j <= 6; j++)
    {
        if (lighttemp[i][j] == 1)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int btnpress(int i, int j)
{
    lighttemp[i][j] = !lighttemp[i][j];
    lighttemp[i - 1][j] = !lighttemp[i - 1][j];
    lighttemp[i + 1][j] = !lighttemp[i + 1][j];
    lighttemp[i][j - 1] = !lighttemp[i][j - 1];
    lighttemp[i][j + 1] = !lighttemp[i][j + 1];
    return 0;
}
int main()
{
    int n, i, j, line1, temp, ansnum = 1, k;
    scanf("%d", &n);
    while (n--)
    {
        for (i = 1; i <= 5; i++)
        {
            for (j = 1; j <= 6; j++)
            {
                scanf("%d", &light[i][j]);
            }
        }
        for (line1 = 0; line1 <= 63; line1++)
        {
            memset(ans, 0, sizeof(ans));
            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j <= 6; j++)
                {
                    lighttemp[i][j] = light[i][j];
                }
            }
            for (temp = line1, k = 1; temp > 0; k++)
            {
                ans[1][k] = temp % 2;
                temp /= 2;
            }
            for (k = 1; k <= 6; k++)
            {
                if (ans[1][k] == 1)
                {
                    btnpress(1, k);
                }
            }
            for (i = 1; i <= 4; i++)
            {
                for (j = 1; j <= 6; j++)
                {
                    if (lighttemp[i][j] == 1)
                    {
                        ans[i + 1][j] = 1;
                        btnpress(i + 1, j);
                    }
                }
            }
            if (iswholelineoff(5))
            {
                printf("PUZZLE #%d\n", ansnum);
                for (i = 1; i <= 5; i++)
                {
                    for (j = 1; j <= 6; j++)
                    {
                        printf("%d ", ans[i][j]);
                    }
                    printf("\n");
                }
                ansnum++;
            }
        }
    }
    return 0;
}