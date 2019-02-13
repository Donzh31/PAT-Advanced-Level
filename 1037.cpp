#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Positive{
    int value;
    bool operator<(const struct Positive &tmp) const
    {
        return value < tmp.value;
    }
};
struct Negative{
    int value;
    bool operator<(const struct Negative &tmp) const
    {
        return value > tmp.value;
    }
};
int main()
{
    priority_queue <struct Positive> p1, p2;
    priority_queue <struct Negative> p3, p4;
    struct Positive tmp;
    struct Negative tmp1;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> tmp.value;
        if(tmp.value >= 0)
            p1.push(tmp);
        else
        {
            tmp1.value = tmp.value;  p3.push(tmp1);
        }
           
    }
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> tmp.value;
        if(tmp.value >= 0)
            p2.push(tmp);
        else
        {
            tmp1.value = tmp.value;  p4.push(tmp1);
        }
          
    }
    int value = 0;
    while(p1.size())
    {
        if(p2.size() > 0)
        {
            value += p1.top().value * p2.top().value;
            p1.pop();
            p2.pop();
        }
        else
            p1.pop();
      
    }
    while(p3.size())
    {
        if(p4.size() > 0)
        {
            value += p3.top().value * p4.top().value;
            p3.pop();
            p4.pop();
        }
        else
            p3.pop();
    }
    cout << value << endl;
}