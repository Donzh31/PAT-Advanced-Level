#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N1, N2;
    //int int a[200005], b[200005];
    int t;
    queue <int> a, b;

    bool flag;
    scanf("%d", &N1);
    for(int i = 0; i < N1; i++)
    {
        scanf("%d", &t);
        a.push(t);
    }
        //scanf("%d", &a[i]);
   
    scanf("%d", &N2);
    int mid;
    if((N1+N2)%2 == 0) //N[t-1] N[t]
    {
        flag = true;
        mid = (N1 + N2)/2 - 1;
    }
    else //N[t]
    {
        flag = false;
        mid = (N1 + N2)/2;
    }
    int c1 = 0, c2 = 0;
    int k = 0;
    for(int i = 0; i<=mid; i++)
    {  
        if(b.size() == 0 && c2 <N2)
        {
            scanf("%d", &t);
            b.push(t);
            c2++;
        }
        
        if(a.size() == 0)
        {
            k = b.front();
            b.pop();
        } 
        else if(b.size() == 0)
        {
            k = a.front();
            a.pop();
        }
        //cout << " get 1 " << c1 << " " << c2;
        else if(a.front() < b.front())
        { 
            // cout << "get 3 ";
            k = a.front();
            a.pop();
        }
        else
        {
            k = b.front();
            b.pop();
        }
        //cout << i << " "<< t << " " << k << endl;
    }
    
    printf("%d", k);
    
}