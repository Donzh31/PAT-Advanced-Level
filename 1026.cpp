#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct Customer{
    int arrive;
    int process;
    int wait;
    int vip;
    int served;
    bool operator<(const Customer &tmp)const
    {
        return arrive > tmp.arrive;
    }
};

struct Table{
    int finish;
    int vip;
    int count;
    bool operator<(const Table &tmp)
    {
        return finish < tmp.finish;
    }
};

int main()
{
    priority_queue <struct Customer> cus, cus_vip;
    struct Table tab[105];
    int cnt = 0;
    int N, K, M;
    int hh, mm, ss, pro, flag, tmp;
    scanf("%d", &N);
    for(int i =0; i< N; i++)
    {
        struct Customer c;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        scanf("%d%d", &pro, &flag);
        tmp = hh * 3600 + mm * 60 + ss;
        if(tmp > 21 * 3600)
            continue;      
        c.arrive = tmp;
        if(pro > 120)
            pro = 120;
        c.process = pro * 60;
        c.served = 0;
        if(flag == 1)
            cus_vip.push(c);
        else
            cus.push(c);
    }
   // cout << cus.size() << " " << cus.top().arrive << " " <<cus.top().process << endl;
   // cout << cus_vip.size() << " " <<cus_vip.top().arrive <<" "<< cus_vip.top().process << endl;
    
    scanf("%d%d", &K, &M);
    for(int i = 0; i<M; i++)
    {
        scanf("%d", &tmp);
        tab[tmp].vip = 1;
    }
    for(int i=1; i<=K; i++)
    {
        tab[i].finish = 8*3600;
        tab[i].count = 0;
        if(tab[i].vip != 1)
            tab[i].vip = 0;
    }
    
    int j = 0, k = 0;
    struct Customer cc;
    int arr, fin, wait;
    for(int i = 8*3600; i<21*3600; i++)
    {
        bool flag = false;
        int t = 0;
         //cout << i << " " << cus_vip.top().arrive << " " << cus.top().arrive << " " << endl;
        if(cus_vip.size() && cus.size() && cus_vip.top().arrive <= i && cus_vip.top().arrive <= i)
        {

            bool hasvip = false;
            int  index = -1;
            for(int j = 1; j<=K; j++)
            {
                if(tab[j].finish <= i && tab[j].vip)
                {
                    index = j;;
                    break;
                }
            }
            if(index != -1)
            {
                cc = cus_vip.top();
                cus_vip.pop();
            }
            else
            {
                for(int j = 1; j<=K; j++)
                {
                    if(tab[j].finish <= i)
                    {
                        index = j;
                        break;
                    }
                }
                if(index != -1)
                {
                    if(cus.top().arrive < cus_vip.top().arrive)
                    {
                        cc = cus.top();
                        cus.pop();
                    }
                    else
                    {
                        cc = cus_vip.top();
                        cus_vip.pop();
                    }
                }
                else
                    continue;
            }
            flag = true;
            fin = tab[index].finish = i + cc.process;
            arr = cc.arrive;
            wait = i - cc.arrive;
            tab[index].count ++;    
            // cout << i << " " << cc.arrive << " " <<cus_vip.top().arrive << " " << cus.top().arrive << " " << endl;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arr/3600, (arr%3600)/60, arr % 60, i/3600, (i%3600)/60, i%60, (wait+30)/60);        
        }
        else if(cus.size() && cus.top().arrive <= i)
        {
            for(int j = 1; j<=K; j++)
            {
                if(tab[j].finish <= i)
                {       
                    cc = cus.top();
                    cus.pop();
                    flag = true;
                    fin = tab[j].finish = i + cc.process;
                    arr = cc.arrive;
                    wait = i - cc.arrive;
                    tab[j].count ++;    
                    //cout << i << " " << cc.arrive << " " <<cus_vip.top().arrive << " " << cus.top().arrive << " " << endl;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arr/3600, (arr%3600)/60, arr % 60, i/3600, (i%3600)/60, i%60, (wait+30)/60);
                    break;
                }
            }
        }
        else if(cus_vip.size() && cus_vip.top().arrive <= i)
        {
            for(int j = 1; j<=K; j++)
            {
                if(tab[j].vip && tab[j].finish <= i)
                {
                    cc = cus_vip.top();
                    cus_vip.pop();
                    flag = true;
                    fin = tab[j].finish = i + cc.process;
                    arr = cc.arrive;
                    wait = i - cc.arrive;
                    tab[j].count ++;    
                    //cout << i << " " << cc.arrive << " " <<cus_vip.top().arrive << " " << cus.top().arrive << " " << endl;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arr/3600, (arr%3600)/60, arr % 60, i/3600, (i%3600)/60, i%60, (wait+30)/60);
                    break;
                }
            }
            if(!flag)
            {
                for(int j = 1; j<=K; j++)
                {
                    if(tab[j].finish <= i)
                    {
                        cc = cus_vip.top();
                        cus_vip.pop();
                        flag = true;
                        fin = tab[j].finish = i + cc.process;
                        arr = cc.arrive;
                        wait = i - cc.arrive;
                        tab[j].count ++;    
                        //cout << i << " " << cc.arrive << " " <<cus_vip.top().arrive << " " << cus.top().arrive << " " << endl;
                        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", arr/3600, (arr%3600)/60, arr % 60, i/3600, (i%3600)/60, i%60, (wait+30)/60);
                        break;
                    }
                }
            }
        }
        /*if(flag)
        {
              printf("%d", tab[1].count);
            for(int i = 2; i<=K; i++)
            {
                printf(" %d", tab[i].count);
            } 
            cout << endl;
        }*/
    
    }
    printf("%d", tab[1].count);
    for(int i = 2; i<=K; i++)
    {
        printf(" %d", tab[i].count);
    } 
    
}