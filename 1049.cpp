#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, c;
    int left = 0, cnt = 1, total = 0;
    cin >> n;
    while(n)
    {
        c = n % 10;
     
        n = n/10;
        if(c == 1)
            total += cnt * n + left + 1;
        else if(c==0)
            total += cnt * n;
        else
            total += (n + 1) * cnt;
        left = left + cnt * c;
        cnt *= 10;  
      
       // cout << c << " "<<n << " " << left<<" " << total << endl;
    }
    cout << total;
}