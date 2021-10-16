#include <stdio.h>
#include <string.h>
int main()
{
    long long int sum, i, temp;
    char a[100000];
    while (scanf("%s", a) != EOF)
    {
        if (a[0] == '0')
            break;
        for (i = 0, sum = 0; i <= strlen(a) - 1; i++)
        {
            sum += a[i] - '0';
        }
        while (sum >= 10)
        {
            temp = sum;
            sum = 0;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}