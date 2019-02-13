#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int max_sum = -1, start = 0, end;
	int cur_sum = 0, cur_sta = 0, cur_end;
	int N, num[10000];
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", num+i);

	end = cur_end = N - 1;
	for(int i = 0; i<N; i++)
	{
		int pre_sum = cur_sum;
		cur_sum += num[i];
		if (cur_sum < 0)
		{
			cur_sum = 0;
			continue;
		}
		if(pre_sum == 0)
			cur_sta = cur_end = i;

		cur_end = i;
		if (cur_sum > max_sum)
		{
			max_sum = cur_sum;
			start = cur_sta;
			end = cur_end;
 		}
	}
	max_sum = max_sum > 0 ? max_sum : 0;
	printf("%d %d %d", max_sum, num[start], num[end]);
}