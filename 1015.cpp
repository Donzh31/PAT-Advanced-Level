#include <stdio.h>
#include <math.h>

int getReverse(int N, int radix)
{
    int R = 0;
    while(N)
    {
        R = R * radix + N % radix;
        N = N / radix;
    }
    return R;
}
int checkPrime(int N)
{
    if(N == 1)
        return 0;
    for(int i = 2; i <= sqrt((double)N); i++)
    {
        if(N % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int N, D, R;
    while(1)
    {
        scanf("%d", &N);
        if(N<0)
            break;
        scanf("%d", &D);
        R = getReverse(N,D);
      //  printf("%d ", R);
        if(checkPrime(N) && checkPrime(R))
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}