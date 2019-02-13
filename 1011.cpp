#include <stdio.h>

int main()
{
    double a, b, c, res =  1;
    
    for(int i = 0; i < 3; i++)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        if(a > b && a > c)
        {
            res *= a;
            printf("W ");
        }
           
        else if(b>a && b>c)
        {
            res *= b;
            printf("T ");
        }
        else if(c>a && c>b)
        {
            res *= c;
            printf("L ");
        }
    }

    res = (res * 0.65 - 1) * 2;
    printf("%.2f", res);
    
}