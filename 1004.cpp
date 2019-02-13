#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int tree[100][100] = {-1};
int leaf[100] = { 0 };
int N, M, curLine, count, tmp;
int maxLevel = 0;
void bfs(int level, int node)
{
	int i = 0;
	if (tree[node][i] == 0)
	{
		maxLevel = maxLevel > level ? maxLevel : level;
		leaf[level]++;
	}
	while (tree[node][i] != 0)
	{
		bfs(level + 1, tree[node][i]);
		i++;
	}
}
int main() 
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &curLine, &count);
		for (int j = 0; j < count; j++)
		{
			scanf("%d", &tmp);
			tree[curLine][j] = tmp;
		}
	}
	bfs(0, 1);
	printf("%d", leaf[0]);
	for (int i = 1; i <= maxLevel; i++)
		printf(" %d", leaf[i]);
}