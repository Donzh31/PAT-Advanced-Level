#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Customer{
    int arrive;
    int process;
    bool operator<(const Customer tmp)const{
        return arrive < tmp.arrive;
    }
} cus[10000];

struct Window{
    int finish_time;
    bool operator<(const Window tmp)const
    {
        return finish_time > tmp.finish_time;
    }
};
int main()
{
    int n, k;
    int h, m, s, t;
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++)
    {
        scanf("%d:%d:%d %d", &h, &m, &s, &t);
        cus[i].arrive = h*3600 + m*60 + s;
        if(cus[i].arrive > 17 * 3600)
        {
            i--;
            n--;
            continue;
        }
        t = t > 60? 60 : t;
        cus[i].process = t * 60;
    }
    int total_wait = 0;
    priority_queue <Window> q;
    Window w;
    for(int i = 0; i<k; i++)
    {
        w.finish_time = 8 * 3600;
        q.push(w);
    }
    sort(cus, cus+n);
    Window ww;
    for(int i = 0; i<n; i++)
    {
        w = q.top();
        q.pop();
        if(cus[i].arrive < w.finish_time)
        {
            total_wait += w.finish_time - cus[i].arrive;
            ww.finish_time = w.finish_time + cus[i].process;
            q.push(ww);
        }
        else
        {
            ww.finish_time = cus[i].arrive + cus[i].process;
            q.push(ww);
        }
    }
    double avg = 1.0 * total_wait / 60 / n;
    printf("%.1lf", avg);
    return 0;

}