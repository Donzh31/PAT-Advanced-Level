#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool visit[10001] = {0};
int level[10001] = {0};
bool root[10001] = {0};
int maxLength = 0;

map<int, vector<int>> road;
queue<int> qu;

void get_deepest(int start, int depth)
{
    visit[start] = 1;
    level[start] = (level[start] > depth)? level[start] : depth;
    //cout << start << " " << depth << " " << level[start] << endl;
    if(road[start].size() == 0)
        return;
    else
    {
        for(int i = 0; i < road[start].size(); i++)
        {
            if(!visit[road[start][i]])
                get_deepest(road[start][i], depth + 1);
           // visit[road[start][i]] = 0;
        }
        visit[start] = 0;
    }
    
}

int main(){
    int N;
    cin >> N;
    int i = 1, from, to;
    while(i<N)
    {
        cin >> from >> to;
        road[from].push_back(to);
        road[to].push_back(from);
        i++;
    }
    int cnt = 0, max = 0, index = 0;
    for(int i = 1; i<=N; i++)
    {
        if(level[i] == 0)
        {
            cnt++;
            get_deepest(i, 1);
            for(int i = 1; i <=N; i++)
            {
                if(level[i] >= max)
                {
                    max = level[i];
                    index = i;
                }
            }
            get_deepest(index, 1);
            for(int i = 1; i <=N; i++)
            {
                if(level[i] >= max)
                {
                    max = level[i];
                    index = i;
                }
            }
            get_deepest(index, 1);
        }
    }
    if(cnt > 1)
        cout << "Error: " << cnt << " components";
    else
        for(int i = 1; i<=N; i++)
        {
            if(level[i] == max)
                cout << i << endl;
        }
    return 0;

}