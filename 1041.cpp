#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<int, int> number;
queue <int> order;
int main(){
    int N, tmp;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &tmp);
        order.push(tmp);
        number[tmp]++;
    }
    int flag = false;
    while(order.size())
    {
        tmp = order.front();
        order.pop();
        if(number[tmp] == 1)
        {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << tmp;
    else
        cout << "None";
    
}