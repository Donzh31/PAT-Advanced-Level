#include <iostream>

using namespace std;

int main()
{
    char initial[25];
    char doubled[25];
    int flag1[10] = {0};
        int flag2[10] = {0};
    int count = 0;
    scanf("%s", initial);
    int i = 0;
    while(i < 21 && initial[i] != 0)
    {
        flag1[initial[i] - '0']++;
        i++;
    }
    int add = 0;
    for(i--; i>=0; i--)
    {
        int tmp = add + (initial[i] - '0') * 2;
        //cout << tmp << endl;
        if(tmp <= 9){
            add = 0;
            doubled[count++] = tmp + '0';
        }
        else
        {
            add = 1;
            doubled[count++] = tmp - 10 + '0';
        }
    }
    int f = 1;
    if(add == 1)
        flag2[1] ++;
    for(int t = count -1; t >= 0; t --)
    {
        flag2[doubled[t] - '0'] ++;
    }
    for(int i=0; i<10; i++)
        if(flag1[i] != flag2[i])
         f= 0;
    if(f == 0)
    {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
    if(add == 1)
        cout << "1";
    for(int t = count -1; t >= 0; t --)
    {
        cout << doubled[t];
    }


}