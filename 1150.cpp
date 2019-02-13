#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int s, e, dis;
	int adj[205][205];
	bool visit[205];
	int order[1000];
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
			adj[i][j] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &s, &e, &dis);
		adj[s][e] = adj[e][s] = dis;
	}
	int K, n;
	scanf("%d", &K);
	int shortest = 999999;
	int sindex = 0;
	for (int i = 0; i < K; i++) 
	{
		for (int j = 0; j <= N; j++)
			visit[j] = false;
		
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", order + j);
		}


		int count = 0, total = 0;
	
		bool simple = true;
		bool na = false;
		count++;
		visit[order[0]] = true;

		for (int j = 1; j < n; j++)
		{
			if (visit[order[j]] && j != n - 1)
				simple = false;
			else if(!visit[order[j]])
			{	
				count++;
				visit[order[j]] = true;
			}
			
		
			if (adj[order[j - 1]][order[j]] != 0)
				total += adj[order[j - 1]][order[j]];
			else
			{
				na = true;
				break;
			}
				
				
		}
		if(na)
			printf("Path %d: NA (Not a TS cycle)\n", i+1);
		else if (count == N && order[n-1] == order[0] && simple)
			printf("Path %d: %d (TS simple cycle)\n", i+1, total);
		else if(count == N && order[n - 1] == order[0] && !simple)
			printf("Path %d: %d (TS cycle)\n", i+1, total);
		else
			printf("Path %d: %d (Not a TS cycle)\n", i+1, total);
		if (shortest > total && count == N && order[n - 1] == order[0])
		{
			shortest = total;
			sindex = i+1;
		}
			

	}
	printf("Shortest Dist(%d) = %d\n", sindex, shortest);
	//cin >> N;
}