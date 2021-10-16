#include "ctype.h"
#include "stdio.h"
#include "string.h"
int main()
{
    char a[100];
    int n, i, p,l;
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        while (n--)
        {
            gets(a);
            l = strlen(a);
            a[l] = '\0';
            for (i = 0, p = 0; a[i] != '\0'; i++)
            {
                if (isdigit(a[i]))
                {
                    p++;
                }
            }
            printf("%d\n", p);
        }
    }
    return 0;
}