#include <stdio.h>
long long int get_real_number(long long radix, char *N)
{
    long long int number = 0;
    int tmp;
    if(radix == 1)
        return -1;
    for(int i = 0; i < 10 && N[i] != 0; i++)
    {
        if(N[i] >= '0' && N[i] <= '9')
            tmp =  N[i] - '0'; 
        else
            tmp = + N[i] - 'a' + 10;
        if(tmp >= radix) 
            return -1;
        number = number * radix + tmp;
       //  printf("%d\n", number);
    } 
    return number;
}
int main()
{
    int i, j;
    long long radix;
    long long int number = 0, res_mid = 0;
    char N[2][11];
    int tag;
    scanf("%s%s", N[0], N[1]);
    scanf("%d%lld", &tag, &radix);
    //printf("%s %s %d %d\n", N[0], N[1], tag, radix);
    number = get_real_number(radix, N[tag - 1]);
    //printf("%lld\n", number);
    long long base = 2, top = number + 1, mid ;
    while(base <= top)
    {
        mid = (top + base)/2;

        res_mid = get_real_number(mid, N[2-tag]);
        // printf("%d %d %d %lld\n", base, mid, top, res_mid);
      
        if(res_mid == -1 || res_mid < number)
        {
            base = mid + 1;
        }
        else if(res_mid == number)
        {
            if(get_real_number(mid - 1, N[2-tag]) != number)
            {
                printf("%lld", mid);
                return 0;
            }
            else
                top = mid - 1;
        }
        else
        {
            top = mid - 1;
        }
    }
    for(int i = 2; i<= mid; i++)
    {
        res_mid = get_real_number(i, N[2-tag]);
        if(res_mid == number)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;    
}