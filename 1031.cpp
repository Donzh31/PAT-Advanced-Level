#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char S[1000];
    scanf("%s", S);
    int n = strlen(S);

    int a = (n%3==0)?n/3-1:n/3;
    int b = n - a *2;
   // cout << n << a << b;
    for(int i = 0; i < a; i++)
    {
        printf("%c", S[i]);
        for(int j = 0; j<b-2; j++)
            printf(" ");
        printf("%c", S[n - 1 - i]);
        printf("\n");
    }
    for(int j = 0; j<b; j++)
        printf("%c", S[a + j]);
}
