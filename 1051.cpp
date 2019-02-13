#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    
    bool flag;
    int num[1001];
    for(int i = 0; i<K; i++)
    {
        for(int j = 0; j<N; j++)
        {
            scanf("%d", num + j);
        }
        num[N] = -1;
        flag = true;
        int cnt = 0;
        stack<int> s;
        for(int j = 1; j<=N; j++)
        {
            
           // cout << "push" << j << endl;
            s.push(j);
        
            while(!s.empty() && s.top() == num[cnt])
            {
                //cout << "pop" << num[cnt] << endl;
                s.pop();
                cnt ++;
            } 
            if(s.size() >= M || (j == N && s.size()))
            {
                flag = false;
                break;
            }
                
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}