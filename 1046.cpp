#include <iostream>
#include <cmath>
//22:43
using namespace std;

int main()
{
    int pre[100005];
    int N, M;
    cin >> N;
    double total = 0;
    int tmp;
    pre[0] = 0;
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &tmp);
        pre[i] = pre[i-1] + tmp;
    }
   
   
    cin >> M;
    int a, b;
    double d1, d2;
    for(int i = 0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        d1 = abs(pre[a-1] - pre[b-1]) ;
        d2 = abs(pre[N] - d1);
        int dis = d1 < d2? d1: d2;
        cout << dis << endl;
    }
}