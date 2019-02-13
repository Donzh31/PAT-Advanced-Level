#include <iostream>

using namespace std;

int N, M, S, D;
int min_distance = 99999, min_cost = 99999;
int final_cnt, final_way[500];
int way[500] = {0};
bool visit[500] = {0};
struct High{
    int distance;
    int cost;
} road[500][500];
void dfs(int city, int current_distance, int current_cost, int cnt)
{
    //cout << "City " << city << " " << current_distance << " " << current_cost<<" " << endl;
    if(city == D)
    {
        if(current_distance < min_distance || (min_distance == current_distance && current_cost < min_cost))
        {
            min_distance = current_distance;
            min_cost = current_cost;
            final_cnt = cnt;
            for(int i = 0; i<cnt; i++)
            {
                final_way[i] = way[i];
            }
        }
        return;
    }
    for(int i = 0; i<N; i++)
    {
        if(!visit[i] && road[city][i].distance != 0)
        {
            visit[i] = 1;
            way[cnt] = i;
            dfs(i, current_distance + road[city][i].distance, current_cost + road[city][i].cost, cnt+1);
            visit[i] = 0;
        }
    }
}

int main()
{
    int from, to, distance, cost;
    scanf("%d%d%d%d", &N, &M, &S, &D);
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
            road[i][j].distance = road[i][j].cost = 0;
    }
    for(int i = 0; i<M; i++)
    {  
        scanf("%d%d%d%d", &from, &to, &distance, &cost);
        road[from][to].distance = road[to][from].distance = distance;
        road[to][from].cost = road[from][to].cost = cost;
    }
    visit[S] = 1;
    cout << S;
    dfs(S, 0, 0, 0);
    for(int i = 0; i<final_cnt; i++)
        cout << " " << final_way[i];
    cout << " " << min_distance << " " << min_cost;

}