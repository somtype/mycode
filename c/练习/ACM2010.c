#include<stdio.h>
int main()
{
	int m, n, sum, i, temp, p;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		if (m > n) { temp = m; m = n; n = temp; }
		for (i = 0; m <= n; m++)
		{
			temp = m;
			sum = 0;
			while (temp)
			{
				p = temp % 10;
				sum += p * p * p;
				temp /= 10;
			}
			if (sum == m)
			{
				if (i == 0)
				{
					printf("%d", m);
					i++;
				}
				else
				{
					printf(" %d", m);
					i++;
				}
			}
		}
		if (i == 0) printf("no\n");
		else printf("\n");
	}
	return 0;
}