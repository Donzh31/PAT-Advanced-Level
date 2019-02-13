#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int k1, k2, k;
    int te, re;
    double tc, rc;
    double p1[20][2] = {0}, res[2001] = {0};
    cin >> k1;
    for(int i=0; i<k1; i++)
    {
        cin >> te >> tc;
        p1[i][0] = te;
        p1[i][1] = tc;
    }
    cin >> k2;
    for(int i=0; i<k2; i++)
    {
        cin >> te >> tc;
        for(int j=0; j<k1; j++)
        {
            re = te + p1[j][0];
            rc = tc * p1[j][1];
            res[re] += rc;
        }
    }
    for(int i=0; i<=2000; i++)
        if(res[i] != 0)
            k++;
    cout << k;
    for(int i=2000; i>=0; i--)
        if(res[i] != 0)
            cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << res[i];
    return 0;
}