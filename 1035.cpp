#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string pname[1005], ppassword[1005];
    string name, password;
    int M = 0;
    for(int i = 0; i<N; i++)
    {
        bool flag = false;
        cin >> name >> password;
        while(password.find("l")!=string::npos)
        {
            flag = true;
            password.replace(password.find("l"),1, "L");
        }
        while(password.find("1")!=string::npos)
        {
            flag = true;
            password.replace(password.find("1"), 1, "@");
        }
        while(password.find("0")!=string::npos)
        {
            flag = true;
            password.replace(password.find("0"), 1,"%");
        }
        while(password.find("O")!=string::npos)
        {
            flag = true;
            password.replace(password.find("O"),1, "o");
        }
        if(flag)
        {
            pname[M] = name;
            ppassword[M] = password;
            M++;
        }
    }
    if(M == 0)
    {
        if(N == 1 || N == 0)
            cout << "There is "<<N<<" account and no account is modified"<<endl;
        else
            cout << "There are "<<N<<" accounts and no account is modified"<<endl;
      
    }
   else
    {
        cout << M << endl;
        for(int i = 0; i<M; i++)
            cout << pname[i] << " " << ppassword[i] << endl;
    }
    return 0;
}
