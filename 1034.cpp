#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map <string, vector<string>> adjlist;
map <string, int> weight;
map <string, int> visit;
map <string, int> result;
int N, K;
int cnt, total;
string head;
void dfs(string start)
{ 
    visit[start] = 1;
    cnt++;
    total += weight[start];
    if(weight[start] > weight[head]) head = start;
    //cout << head << " " << start << " " << cnt << " " << total << endl;
  
   
    vector<string>::iterator it=adjlist[start].begin();
 
    for(;it!=adjlist[start].end();it++)
    {
       if(visit[*it]==0)
       {
           dfs(*it);
       }
    }
}
int main()
{
    string name1, name2;
    int time;
    cin >> N >> K;
    for(int i =0; i<N; i++)
    {
        cin >> name1 >> name2 >> time;
        adjlist[name1].push_back(name2);
        adjlist[name2].push_back(name1);
        weight[name1] += time;
        weight[name2] += time;
        visit[name1] = 0;
        visit[name2] = 0;
    }
    map <string, int>::iterator ite = visit.begin();
    for(; ite != visit.end(); ite++)
    {
        if(ite->second == 0)
        {
            total = 0;
            cnt = 0;
            head = ite->first;
            dfs(ite->first);
        }
        if(K * 2 < total && cnt >= 3)result[head] = cnt;
    }
    map<string,int>::iterator it=result.begin();
    cout<<result.size()<<endl;
    for(;it!=result.end();it++)cout<<it->first<<" "<<it->second<<endl;
    return 0;

}