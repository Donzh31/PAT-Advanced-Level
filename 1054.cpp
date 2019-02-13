#include <iostream>
#include <map>

using namespace std;
map<int, int> color;
int main()
{
    int N, M;
    cin >> N >> M;
    int tmp;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            scanf("%d",&tmp);
            color[tmp] ++;
        }
    }
    map<int, int>::iterator ite;
    for(ite = color.begin(); ite != color.end(); ite++)
    {
        if((ite->second) > M * N / 2)
        {
            cout << ite->first;
            break;
        }
    }
}