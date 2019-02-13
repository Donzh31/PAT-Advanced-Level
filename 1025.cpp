#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node{
    string reg_num;
    int score;
    int location;
    int final_rank;
    int local_rank;
}a[105*305];

bool cmp(const Node a, const Node b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.reg_num < b.reg_num;
}

int main()
{
    int N, K;
    int count = 0;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> K;
        for(int j = 0; j<K; j++)
        {
            cin >> a[count].reg_num >> a[count].score;
           // scanf("%s%d", a[count].reg_num, &a[count].score);
            a[count].location = i + 1;
            count ++;
        }
        sort(a+count-K, a+count, cmp);
        int local_rank = 1, pre_score = a[count - K].score;
        for(int j = count - K; j<count; j++)
        {
            if(pre_score == a[j].score)
            {
                a[j].local_rank = local_rank;
            }
            else{
                a[j].local_rank = j - count + K + 1;
                pre_score = a[j].score;
                local_rank = a[j].local_rank;
            }
        }
    }
       cout << count << endl;
    sort(a, a+count, cmp);
    int fin_rank = 1, pre_score = a[0].score;
    for (int j = 0; j<count; ++j)
    {
        if (a[j].score != pre_score) //与前一个同分
        {
            fin_rank = j + 1;
            pre_score = a[j].score;
        }
        a[j].final_rank = fin_rank;
        cout << a[j].reg_num << ' ' << a[j].final_rank << ' ' << a[j].location << ' ' << a[j].local_rank << endl;
    }
    /*
    sort(a, a+count, cmp);
    int final_rank = 1, pre_score = a[0].score;

    for(int j = 0; j<count; j++)
    {
        if(pre_score == a[j].score)
        {
            a[j].final_rank = final_rank;
        }
        else{
            a[j].final_rank = j + 1;
            pre_score = a[j].score;
            final_rank = j + 1;
        }
    }
    cout << count << endl;
    for(int i = 0; i < count; i++)
    {
        cout << a[i].reg_num << " " << a[i].final_rank << " " << a[i].location << " " << a[i].local_rank << endl;
    }*/
}