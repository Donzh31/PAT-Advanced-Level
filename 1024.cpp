#include <iostream>
#include <cstring>
using namespace std;

int check_paildromic(char *s, int length)
{
    int flag = 1;
    for(int i = 0; i<length/2; i++)
    {
        if(s[i] != s[length - 1 - i])
            flag = 0;
    }
    return flag;
}
int double_s(char *s, int length)
{
    int i = 0, c = 0, tmp, count = 0;
    char res[1000];
    for(i = length - 1; i >= 0; i--)
    {
        tmp = c + s[i] + s[length - 1 - i] - '0' - '0';
    
        if(tmp > 9)
        {
            c = 1;
            res[count++] = tmp - 10 + '0'; 
        } 
        else
        {
            c = 0;
            res[count++] = tmp + '0';
        }
    }
    i = 0;
    if(c == 1)
        s[i++] = '1';
    for(int j=count-1; j>=0; j--)
    {
        s[i++] = res[j];
    }
    if(c == 1)
        return length + 1;
    else 
        return length;
}
int main()
{
    char a[200];
    int k, t = 0;
    scanf("%s%d", a, &k);
    
    int length = strlen(a), carry = 0;
    


    while(!check_paildromic(a, length) && t < k)
    {
        t++;
        length = double_s(a, length);
       // cout << length << " "<< a << endl;
    }    
    a[length] = 0;
    cout << a << endl;
    cout << t;

}