#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

map <int, int> l;

int main()
{
    int s1, s2, N;
    int cnt;
    int next;
    char c;
    int L1[100001];
    scanf("%d%d%d", &s1, &s2, &N);
    //cout << s1 << s2 << N;
    for(int i = 0; i<N; i++)
    {
        //cin >> cnt >> c >> next;

		scanf("%d %c %d", &cnt, &c, &next);
        //scanf("%d%c%d", &cnt, &node.c, &node.next);
        l[cnt] = next;
        //cout << cnt << c << next << endl;
    }
    //cout << cnt;
    
    for(int i = 0; i<100001; i++)
        L1[i] = -2;
    int t1 = s1;
    while(t1 != -1)
    {
        L1[t1] = l[t1];
        t1 = l[t1];
    }

    int t2 = s2;
    while(L1[t2] == -2 && t2 != -1)
    {
        t2 = l[t2];
    }

    if(L1[t2] != -2 && t2 != -1)
    {
        printf("%05d", t2);
    }
    else
        printf("-1");
    return 0;

}
