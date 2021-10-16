#include<stdio.h>
int main()
{
	int i, n, x, y,sum,p,q;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x == 0 && y == 0) break;
		for (n = x; n <= y; n++)
		{
			sum = n * n + n + 41;
			for (i = 2, p = 0; sum % i != 0 && i < sum; i++) p++;
			if (p == sum - 2)
			{
				q = 1;
				continue;
			}
			else
			{
				q = 0;
				break;
			}
		}
		if (q) printf("OK\n");
		else printf("Sorry\n");
	}
	return 0;
}