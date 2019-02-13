#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct Number{
    string number;
    bool operator<(const struct Number tmp) const{
        string n1 = number + tmp.number;
        string n2 = tmp.number + number;
        return n1 > n2;
    }
};
int main()
{
    int N;
    string number;

    cin >> N;
    priority_queue <struct Number> num, first_zero;
    for(int i = 0; i<N; i++)
    {
        cin >> number;
        struct Number n;
        n.number = number;
        num.push(n);
    }
    number = "";
    while(num.size())
    {
        number += num.top().number;
        num.pop();
    }
   
    while(number.find('0') == 0)
        number.replace(0, 1, "");
    if(number == "")
        cout << "0";
    else
       cout << number;

    
   
}