#include<stdio.h>
int main()
{
	int a[100] = { 0 }, n, i, min, temp;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		else
		{
			for (i = 0; i <= n - 1; i++)
			{
				scanf("%d", &a[i]);
			}
			min = a[0];
			for (i = 0; i <= n - 1; i++)
			{
				if (a[i] < min) min = a[i];
			}
			for (i = 0; i <= n - 1; i++)
			{
				if (a[i] == min) break;
			}
			temp = a[0]; a[0] = a[i]; a[i] = temp;
			for (i = 0; i <= n - 1; i++)
			{
				if (i == 0) printf("%d", a[i]);
				else printf(" %d", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}