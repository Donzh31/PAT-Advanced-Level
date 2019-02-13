#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char num[100];
	int res[10];
	int sum = 0, i = 0;
	char NUM[10][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	scanf("%s", num);
	while (num[i])
	{
		sum += num[i] - '0';
		i++;
	}
	i = 0;
	while (sum)
	{
		res[i] = sum % 10;
		i++;
		sum = sum / 10;
	}
	printf("%s", NUM[res[--i]]);
	for(i--; i>=0; i--)
		printf(" %s", NUM[res[i]]);
}