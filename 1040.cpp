#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int max_length = 1;
    getline(cin, str,'\n');
    for(int i = 0; i<str.length(); i++)
    {
        for(int j = i+1; j<str.length(); j++)
        {
            bool flag = true;
            for(int k = 0; k<=(j-i)/2; k++)
            { 
               //cout << str.at(j-k) << "&" << str.at(i+k)<< " " ;
                if(str.at(j-k) != str.at(i+k))
                {
                     flag = false;
                     break;
                }
                   
            }
            if(flag &&( j - i + 1 > max_length))
                max_length = j - i + 1;
           // cout << i << " " << j<< " " << max_length << endl;
        
        }
    }
    cout << max_length;
}