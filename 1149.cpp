#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

map <int, set<int>> incompatibles;
int main() {
	int M, N, K;
	int s1, s2;
	int list[1005];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &s1, &s2);
		incompatibles[s1].insert(s2);
		incompatibles[s2].insert(s1);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &K);
		int tail = 0, tmp;
		bool flag = false;
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &tmp);
			if (incompatibles[tmp].empty())
				continue;
			else
				list[tail++] = tmp;
		
		}	
		for (int k = 0; k < tail; k++)
		{
			for (int n = k + 1; n < tail; n++)
			{
				if (incompatibles[list[k]].find(list[n]) != incompatibles[list[k]].end())
				{
					flag = true;
					break;
				}	
			}
			if (flag)
				break;
						
		}
		if (flag == true)
			printf("No\n");
		else
			printf("Yes\n");
	}
		


}