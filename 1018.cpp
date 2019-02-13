#include <cstdio>
#include <queue>
using namespace std;

int C, N, S, M;
int cur[505];
int road[505][505];
int min_queue[505];
int min_length;
int min_road = 99999;
int allbring = 99999;
int allback = 99999;
int cur_queue[505];
int cur_length;
int visited[505] = {0};

void dfs(int now, int now_road, int bring, int back)
{
    //printf("%d %d %d %d %d %d %d\n", now, now_road, bring, back, min_road, bring, back);
    if(now == S)
    {
        if(now_road < min_road)
        {
            min_road = now_road;
            allbring = bring;
            allback = back;
            min_length = cur_length;
            for(int i = 0; i<cur_length; i++)
            {
                min_queue[i] = cur_queue[i];
            }
        }
        if(now_road == min_road)
        {
            if(bring < allbring || (bring == allbring && back < allback))
            {
                min_road = now_road;
                allbring = bring;
                allback = back;
                min_length = cur_length;
                for(int i = 0; i<cur_length; i++)
                {
                    min_queue[i] = cur_queue[i];
                }
            }
        }
        
    }
    if(now_road >= min_road)
        return;
    for(int i = 0; i<N + 1; i++)
    {
        if(road[now][i] != 0 && !visited[i])
        {
            visited[i] = 1;
            cur_queue[cur_length++] = i;
            int tbring, tback;
            if(cur[i] - C/2 >= 0)
            {
                tbring = bring;
                tback = back + cur[i] - C/2;
            }
            else if(back + cur[i] - C/2 >= 0)
            {
                tbring = bring;
                tback = back + cur[i] - C/2;
            }
            else
            {
                tback = 0;
                tbring = bring + C/2 - back - cur[i];
            }
            dfs(i, now_road + road[now][i], tbring, tback);
            cur_length--;
            visited[i] = 0;
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &C, &N, &S, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%d", cur + i + 1);
    }
    for(int i = 0; i<M; i++)
    {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        road[a][b] = road[b][a] = l;
    }
    visited[0] = 1;
    dfs(0, 0, 0, 0);
        printf("%d ", allbring);
    
    printf("0");
    for(int i = 0; i<min_length; i++)
        printf("->%d", min_queue[i]);
   
        printf(" %d", allback);

}