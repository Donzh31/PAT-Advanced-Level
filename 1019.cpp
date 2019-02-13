#include <iostream>

using namespace std;

int main()
{
    int N, b, flag = 1;
    int C[100], length = 0;
    scanf("%d%d", &N, &b);
    if(N == 0)
        C[length ++] = 0;
    else
    {
        while(N)
        {
            C[length ++] = N % b;
            N = N/b;
        }
    }

    for(int i = 0; i<length/2; i++)
    {
        if(C[i] != C[length - 1 - i])
         {
             flag = 0;
             break;
         }   
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    printf("%d", C[length - 1]);
    for(int i = length - 2; i>=0; i--)
        printf(" %d", C[i]);
}