#include <stdio.h>
   
int N, M, K;
int HighWays[1000][1000] = {0};
int visited[1000] = {0};
int area = 0;

void getConnections(int city)
{
    for(int i = 1; i<=N; i++)
    {
        /*  for(int i = 1; i<= N; i++)
                printf("%d", visited[i]);
            printf("\n");*/
        if(!visited[i] && HighWays[city][i] == 1 )
        {
            visited[i] = 1;
            getConnections(i);
        }
    }
}
int FindRepairedWays()
{
    
    for(int i = 1; i<=N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            getConnections(i);
            area ++;
        }
    }
    return area;

}

int main(int argc, char const *argv[])
{
 
    int s, e, city, count;

    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &s, &e);
        HighWays[s][e] = HighWays[e][s] = 1;
    }
    for(int i=0; i<K; i++)
    {

        scanf("%d", &city);
   
        for(int i = 1; i <= N; i++)
            visited[i] = 0;
        area = 0;
        visited[city] = 1;
        count = FindRepairedWays();
        printf("%d\n", count - 1);
    }
    return 0;
}
