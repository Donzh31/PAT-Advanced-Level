#include <iostream>
#include <cstring>
#include <sstream>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;

struct Book{
    string id;
    string title;
    string author;
    string publisher;
    string year;
} book[10001];

map<string, vector<string>> keymap;

bool cmp(Book a, Book b)
{
    return a.id < b.id;
}

int main()
{
    int N;
    cin >> N;
    getchar();
    string keyword, tmp;
    for(int i=0; i<N; i++)
    {
      //  cin >> book[i].id;
        //getchar();
        getline(cin, book[i].id, '\n');
        //cout << book[i].id << "hhhh";
        getline(cin, book[i].title, '\n');
        getline(cin, book[i].author, '\n');
        getline(cin, keyword, '\n');
        istringstream is(keyword);
        while(is>>tmp)
            keymap[tmp].push_back(book[i].id);
        getline(cin, book[i].publisher, '\n');
        getline(cin, book[i].year, '\n');
    }
    sort(&book[0], &book[N], cmp);
    int M;
    cin>>M;
    int index;
    string query;
    for(int i=0; i<M; i++)
    {
        int flag = 0;
        scanf("%d: ", &index);
        getline(cin, query, '\n');
        cout << index << ": " << query << endl;
        if(index==1)
        {
            for(int k=0;k<N;k++)
            {
                if(book[k].title==query)
                {
                    flag=1;
                    cout<<book[k].id<<endl;
                }
            }
        }
        else if(index==2)
        {
            for(int k=0;k<N;k++)
            {
                if(book[k].author==query)
                {
                    flag=1;
                    cout<<book[k].id<<endl;
                }
            }
        }
        else if(index==3)
        {
            sort(keymap[query].begin(),keymap[query].end());
            if(keymap[query].size()>0)
            {
                flag=1;
                vector<string>::iterator iter=keymap[query].begin();
                for(;iter!=keymap[query].end();iter++)
                {
                    cout<<*iter<<endl;
                }
            }
        }
        else if(index==4)
        {
            for(int k=0;k<N;k++)
            {
                if(book[k].publisher==query)
                {
                    flag=1;
                    cout<<book[k].id<<endl;
                }
            }
        }
        else
        {
            for(int k=0;k<N;k++)
            {
                if(book[k].year==query)
                {
                    flag=1;
                    cout<<book[k].id<<endl;
                }
            }
        }
        if(flag==0)cout<<"Not Found"<<endl;
    }
    return 0;

}