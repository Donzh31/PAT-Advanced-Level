#include <stdio.h>

int main()
{
	int i = 0, tmp[10];
	long a, b, res;
	scanf("%ld%ld", &a, &b);
	res = a + b;
	if (res < 0)
	{
		printf("-");
		res = -res;
	}
	while (res >= 1000)
	{
		tmp[i++] = res % 1000;
		res /= 1000;
	}
	printf("%d", res);
	i--;
	for (; i >= 0; i--)
	{
		printf(",%03d", tmp[i]);
	}
	return 0;
}