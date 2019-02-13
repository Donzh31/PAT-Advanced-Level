#include <iostream>

using namespace std;

int main()
{
    int N, M, num[100005];
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &num[i]);
    }    
    int next_min = 999999;  
    int next_start = 0; 
    bool flag = false;
    bool f;
    int k = 0, total = 0;
    int j;
    for(int i = 0; i<N; i++)
    {
        for(j = k; j<N; j++)
        {
            total += num[j];
           // cout << total << " " << i << " " << j <<" " << k << endl;
            if(total == M)
            {
                printf("%d-%d\n", i+1, j+1);
                total = total - num[i] - num[j];
                flag = true;
                k = j;
                break;
            }
            else if(total > M)
            {   
                if(!flag)
                {
                    next_min = next_min > total? total : next_min;
                    next_start = next_min > total? i : next_start;
                    
                }
                total = total - num[i] - num[j];
                k = j;
                break;
            }
        }
        if(j == N)
            break;
               
    }
    
    if(flag == false)
    {
        k = 0, total = 0;
        for(int i = 0; i<N; i++)
        {
            for(j = k; j<N; j++)
            {
                total += num[j];
                if(total == next_min)
                {
                    printf("%d-%d\n", i+1, j+1);
                    total = total - num[i] - num[j];
                    k = j;
                    break;
                }
                else if(total > next_min)
                {   
                    total = total - num[i] - num[j];
                    k = j;
                    break; 
                }
            }
            if(j == N)
                break;
        }
    }
}