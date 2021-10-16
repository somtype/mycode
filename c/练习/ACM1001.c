#include"stdio.h"
int main()
{
	int n, sum=0,i;
	while (scanf("%d", &n)!=EOF)
	{
		for (i = 1; i <= n; i++)
		{
			sum = sum + i;
		}
		printf("%d\n\n", sum);
		sum = 0;
	}
	return 0;
}