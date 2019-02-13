#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int father[1001];
int getfather(int x)
{
    if(father[x] == x)
        return x;
    else    
        return getfather(father[x]);
}
void Merge(int a, int b)
{
    int f1 = getfather(a);
    int f2 = getfather(b);
    father[f2] = f1;
}
bool cmp(const int &a, const int &b)
{
    return a>b;
}
int main(){
    int N, k, t;
    cin >> N;
    vector <int> hobby[1001];
    int exist[1001] = {0};
    for(int i = 1; i<=N; i++)
    {
        scanf("%d:", &k);
        for(int j = 0; j<k; j++)
        {
            scanf("%d", &t);
            hobby[t].push_back(i);
            exist[t] = 1;
        }
    }

    for(int i = 1; i<1001; i++)
        father[i] = i;
    vector <int>::iterator ite;
    int sta;
    for(int i = 1; i<1001; i++)
    {
        if(exist[i]){
            sort(hobby[i].begin(), hobby[i].end(), cmp);
            ite = hobby[i].begin();
            sta = *ite;
            for(; ite!=hobby[i].end(); ite++)
            {
                Merge(sta, *ite);
            }
           
        }
    }
    for(int i = 1; i<=N; i++)
        father[i] = getfather(i);
        
    int count[1001];
    int cnt = 0;
    for(int i = 1; i<=N; i++)
        count[i] = 0;
    for(int i = 1; i<=N; i++)
        count[father[i]]++;
    sort(count + 1, count + N + 1, cmp);
    for(int i = 1; i<=N; i++)
    {
        if(count[i] != 0)
            cnt = i;
    }
    cout << cnt << endl;
    cout << count[1];
    for(int i = 2; i<=cnt; i++)
        cout << " " << count[i];


}