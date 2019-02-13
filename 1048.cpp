#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    int num[100005];
    int a;
    cin >> N >> M;
    for(int i = 0; i<N; i++)
    {
        scanf("%d", num + i);
    }
    sort(num, num + N);
    bool flag = false;
    int k = N - 1;
    for(int i = 0; i<N; i++)
    {
        if(num[i] >= M || flag) 
            break;
        for(int j = k; j > i; j--)
        {
            //cout << i << " " << j << " " << num[i] << " "<< num[j] << endl;
            if(num[i] + num[j] == M)
            {
                cout << num[i] << " " << num[j];
                flag = true;
                break;
            }
            else if(num[i] + num[j] < M)
            {
                k = j + 1;
                break;
            }
        }
    }
    if(!flag)
        cout << "No Solution";
}