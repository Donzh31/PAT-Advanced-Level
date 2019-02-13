#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
    int N, M, m;
    cin >> N >> M;
    map <int ,vector <string>> course;
    string name;
    int c;
    for(int i = 0; i<N;i++)
    {
        //cin >> name >> m;
        //cout << name << endl;
        cin >> name;
        scanf("%d", &m);
        for(int j = 0; j<m; j++)
        {
            scanf("%d", &c);
            course[c].push_back(name);
        }
    }  
     vector<string>::iterator ite;
    for(int i = 1; i<= M; i++)
    {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end());
     
        for(ite = course[i].begin(); ite!=course[i].end(); ite++)
          {
            cout << *ite;
            printf("\n");
          }  
    }
  
    return 0;
}