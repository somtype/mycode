#include<stdio.h>
int main()
{
	char c[3], n;
	while (scanf("%s", c) != EOF)
	{
		if (c[0] > c[1])
		{
			n = c[0]; c[0] = c[1]; c[1] = n;
		}
		if (c[0] > c[2])
		{
			n = c[0]; c[0] = c[2]; c[2] = n;
		}
		if (c[1] > c[2])
		{
			n = c[1]; c[1] = c[2]; c[2] = n;
		}
		printf("%c %c %c\n", c[0], c[1], c[2]);
	}
	return 0;
}