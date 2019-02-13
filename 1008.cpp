#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int N;
	int cur = 0, next;
	int time = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &next);
		if (next > cur)
			time += (next - cur) * 6;
		else if (next < cur)
			time += (cur - next) * 4;
		time += 5;
		cur = next;
	}
	printf("%d", time);

}