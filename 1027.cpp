#include <iostream>

using namespace std;

int main()
{
    int c[3];
    char N[13] = {'0', '1', '2', '3', '4','5','6','7', '8','9','A', 'B', 'C'};
    cin >> c[0] >> c[1] >> c[2];
    cout << "#";
    for(int i = 0; i<3; i++)
    {
        if(c[i] < 13)
        {
            cout << '0' << N[c[i]];
        }
        else
        {
            cout << N[c[i]/13] << N[c[i]%13];
        }
    }
}