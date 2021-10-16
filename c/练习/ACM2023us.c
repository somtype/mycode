#include<stdio.h>
int main(void)
{
	double n, m, a, b;
	int i, j, A, B;
	double e[50][5];
	double f[5];
	while (scanf("%lf %lf", &n, &m) != EOF)
	{
		a = 0;
		b = 0;
		B = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%lf", &e[i][j]);
			}
		}
		
		for (j = 0; j < n; j++)
		{
			a = 0;
			for (i = 0; i < m; i++)
			{
				a += e[j][i];
			}
			
			if (j == 0)
			{
				printf("%.2f", a/m);
			}
			else
			{
				printf(" %.2f", a/m);
			}
		}
		printf("\n");
		for (i = 0; i < m; i++)
		{
			b = 0;
			for (j = 0; j < n; j++)
			{
				b += e[j][i];
			}
			f[i] = b / n;
			if (i == 0)
			{
				printf("%.2f", f[i]);
			}
			else
			{
				printf(" %.2f",f[i]);
			}
		}
		printf("\n");
		for (i = 0; i < n; i++)
		{
			A = 0;
			for (j = 0; j < m; j++)
			{
				if (e[i][j] >= f[j])
					A++;
			}
			if (A == m)
				B++;
		}
		printf("%d\n\n", B);
	}
	return 0;
}
