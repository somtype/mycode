#include "stdio.h"
#include "string.h"
int main()
{
    int isTheCoin(char icoin, char left[][7], char right[][7], char result[][7], int islight);
    int n, t, i;
    char icoin;
    char left[3][7], right[3][7], result[3][7];
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0; i < 3; ++i)
        {
            scanf("%s%s%s", left[i], right[i], result[i]);
        }
        for (icoin = 'A'; icoin <= 'L'; ++icoin)
        {
            if (isTheCoin(icoin, left, right, result, 1))
            {
                printf("%c is the counterfeit coin and it is light.", icoin);
                break;
            }
            else if (isTheCoin(icoin, left, right, result, 0))
            {
                printf("%c is the counterfeit coin and it is heavy.", icoin);
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}
int isTheCoin(char icoin, char left[][7], char right[][7], char result[][7], int islight)
{
    char *pleft, *pright;
    int i;
    for (i = 0; i < 3; ++i)
    {
        if (islight)
        {
            pleft = left[i];
            pright = right[i];
        }
        else
        {
            pleft = right[i];
            pright = left[i];
        }
        switch (result[i][0])
        {
        case 'u':
            if (strchr(pright, icoin) == 0)
                return 0;
            break;
        case 'e':
            if (strchr(pleft, icoin) || strchr(pright, icoin))
                return 0;
            break;
        case 'd':
            if (strchr(pleft, icoin) == 0)
                return 0;
            break;
        }
    }
    return 1;
}