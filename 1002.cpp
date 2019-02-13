#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count, exp, item = 0;
	double coe;
	double res[1001] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &count);
		for (int j = 0; j < count; j++)
		{
			scanf("%d%lf", &exp, &coe);
			if (res[exp] == 0)
				item++;
			res[exp] += coe;
			if (res[exp] == 0)
				item--;
		}
	}
	printf("%d", item);
	for (int i = 1000; i >= 0; i--)
		if (res[i])
			printf(" %d %.1lf", i, res[i]);
}