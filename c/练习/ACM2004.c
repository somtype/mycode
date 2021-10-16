#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    while (scanf("%d", &a) != EOF)
    {
        if (a >= 0 && a <= 59)
            printf("E\n");
        else if (a >= 60 && a <= 69)
            printf("D\n");
        else if (a >= 70 && a <= 79)
            printf("C\n");
        else if (a >= 80 && a <= 89)
            printf("B\n");
        else if (a >= 90 && a <= 100)
            printf("A\n");
        else
            printf("Score is error!\n");
    }
    return 0;
}