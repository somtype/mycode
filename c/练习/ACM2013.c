#include<stdio.h>
int main()
{
	int a[100], n, i, m, t;
	double aver;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
		for (i = 0; i <= n - 1; i++)
		{
			for (m = 0; m <= n - 2; m++)
			{
				if (a[m] > a[m + 1])
				{
					t = a[m];
					a[m] = a[m + 1];
					a[m + 1] = t;
				}
			}
		}
		for (m = 1, aver = 0; m <= n - 2; m++) aver += a[m];
		aver /= (n - 2);
		printf("%.2f\n", aver);
	}
	return 0;
}