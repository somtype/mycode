#include<stdio.h>
int main()
{
	int a[101], i, n, m, p = 0;
	for (i = 1; i <= 100; i++) a[i] = 2 * i;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= n;)
		{
			int ans, j;
			for (ans = 0, j = 1; j <= m && i <= n; j++, i++)
			{
				ans += a[i];
			}
			ans /= j - 1;
			if (p == 0)
			{
				printf("%d", ans); p++;
			}
			else printf(" %d", ans);
		}
		printf("\n");
		p = 0;
	}
	return 0;
}