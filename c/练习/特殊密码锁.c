#include "stdio.h"
#include "string.h"
char lock[32], locktemp[32], ans[32];
int btnpress(int i)
{
    locktemp[i] = !locktemp[i];
    locktemp[i - 1] = !locktemp[i - 1];
    locktemp[i + 1] = !locktemp[i + 1];
    return 0;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    gets(lock);
    gets(ans);
    int n = strlen(lock), i, num1 = 0, num2 = 1, flag1, flag2;
    for (i = 0; i <= n - 1; i++)
    {
        lock[i] -= 48;
        ans[i] -= 48;
        locktemp[i] = lock[i];
    }
    for (i = 0; i <= n - 2; i++)
    {
        if (locktemp[i] != ans[i])
        {
            btnpress(i + 1);
            num1++;
        }
    }
    if (locktemp[n - 1] == ans[n - 1])
    {
        flag1 = 1;
    }
    else
    {
        flag1 = 0;
        num1 = n + 2;
    }
    for (i = 0; i <= n - 1; i++)
    {
        locktemp[i] = lock[i];
    }
    btnpress(0);
    for (i = 0; i <= n - 2; i++)
    {
        if (locktemp[i] != ans[i])
        {
            btnpress(i + 1);
            num2++;
        }
    }
    if (locktemp[n - 1] == ans[n - 1])
    {
        flag2 = 1;
    }
    else
    {
        flag2 = 0;
        num2 = n + 2;
    }
    if (flag1 || flag2)
    {
        printf("%d", min(num1, num2));
    }
    else
    {
        printf("impossible");
    }
    return 0;
}