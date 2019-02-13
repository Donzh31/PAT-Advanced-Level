#include <iostream>
#include <algorithm>
using namespace std;

struct Station{
    double price;
    int distance;
    bool operator<(const struct Station tmp) const
    {
        if(distance != tmp.distance)
            return distance < tmp.distance;
        else
            return price < tmp.price;
    }
}s[505];

int main()
{
    int C, D, A, N;
    double price;
    int distance;
    scanf("%d%d%d%d", &C, &D, &A, &N);
    for(int i = 0; i<N; i++)
    {
        scanf("%lf%d", &price, &distance);
        s[i].price = price;
        s[i].distance = distance;
    }
    s[N].price = 0;
    s[N].distance = D;

    sort(s, s+N + 1);

  //  for(int i = 0; i<=N; i++)
   //     printf("%lf %d\n", s[i].price, s[i].distance);
    
    if(s[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    price = 0;
    double left_distance = 0;
    double max_distance = C * A; 
    for(int i = 0; i<=N; i++)
    {
        if(s[i].distance == D)
        {
            printf("%.2lf", price);   
            break;         
        }
        //cout << i << " left distance " << left_distance << " price " << price << " distance " << s[i].distance << endl;
        int tmp = i+1, less_price = s[i].price, less_index = i;
        while(s[tmp].distance <= s[i].distance + max_distance)
        {
            if(s[tmp].price <= s[i].price)
            {
                less_price = s[tmp].price;
                less_index = tmp;
                break;
            }
            else tmp ++;
        }
        
        if(less_index != i)
        {
          
            if(s[less_index].distance <= D)
            {  
                if(left_distance + s[i].distance >= s[less_index].distance)
                {
                    left_distance = left_distance - (s[less_index].distance - s[i].distance);
                    i = less_index - 1;
                 //   cout << "less index "<< less_index << endl;
                }
                else{
                    price += (s[less_index].distance - s[i].distance - left_distance) / A * s[i].price;
                    i = less_index - 1;
                   // cout << "less index "<< less_index << endl;
                    left_distance = 0;
                }
                
            }
        }
        else
        {
            price += (C - left_distance / A) * s[i].price;
            left_distance = max_distance - s[i+1].distance + s[i].distance;
            if(left_distance < 0)
            {
                printf("The maximum travel distance = %.2lf", s[i].distance + max_distance);
                return 0;
            }
           
        }

        
    }
}