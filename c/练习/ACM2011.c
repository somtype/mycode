#include<stdio.h>
int main()
{
	double sum;
	int n, m, i1,i2,sign;
	while (scanf("%d", &n) != EOF)
	{
		for (i1 = 1; i1 <= n; i1++)
		{
			scanf("%d", &m);
			for (sum = 0, i2 = 1,sign=1; i2 <= m; i2++)
			{
				sum += 1.0 / i2 * sign;
				sign *= -1;
			}
			printf("%.2f\n", sum);
		}
	}
	return 0;
}