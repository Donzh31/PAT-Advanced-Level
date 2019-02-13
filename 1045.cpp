#include <iostream>
#include <map>
//20:30
using namespace std;

int N, M, L;
int all[10005];
int favor[205];
int res[205][10005];

int main()
{
    cin >> N >> M;
    int color;
    for(int i = 0; i<M; i++)
    {
        scanf("%d", &color);
        favor[i + 1] = color;
    }
    cin >> L;
    for(int i = 0; i<L; i++)
    {
        scanf("%d", all + i + 1);
    }
    int max;
    for(int i = 1; i<=M; i++)
    {
        for(int j = 1; j<=L; j++)
        {
            max = res[i-1][j-1];
            if(max < res[i][j-1])
                max = res[i][j-1];
            if(max < res[i-1][j])
                max = res[i-1][j];
            if(favor[i] == all[j])
                res[i][j] = max + 1;
            else
                res[i][j] = max;
        }
       
    }
    cout << res[M][L];
}