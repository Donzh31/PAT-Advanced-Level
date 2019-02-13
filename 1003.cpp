#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, sta, des;
int team[500];
int visited[500] = { 0 };
int road[500][500] = { 0 };
int count = 0;
int max_team = 0;
int min_dis = 99999;
void dfs(int sta, int des, int cur_dis, int cur_team)
{
	if (sta == des)
	{
		if (cur_dis < min_dis)
		{
			min_dis = cur_dis;
			count = 1;
			max_team = cur_team;
		}
		else if (cur_dis == min_dis)
		{
			count++;
			max_team = cur_team > max_team ? cur_team : max_team;
		}
	}

	if (cur_dis > min_dis)
		return;

	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && road[sta][i])
		{
			visited[i] = 1;
			dfs(i, des, cur_dis + road[sta][i], cur_team + team[i]);
			visited[i] = 0;
		}
	}
}

int main()
{
	int j, k, dis;
	scanf("%d%d%d%d", &N, &M, &sta, &des);
	for (int i = 0; i < N; i++)
		scanf("%d", team + i);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &j, &k, &dis);
		road[j][k] = road[k][j] = dis;
	}
	visited[sta] = 1;
	dfs(sta, des, 0, team[sta]);
	printf("%d %d", count, max_team);
	return 0;
}