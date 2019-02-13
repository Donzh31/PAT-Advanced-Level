#include <stdio.h>
#include <string.h>

int get_order(int *order, double *data, int N)
{
    double max = -1, pre_max = max;
    int index = -1, pre_index = index;
    int count = 0;
    int flag[2001] = {0}; 
    for(int i = 0; i<N; i++)
    {
        max = -1;
        for(int j = 0; j<N; j++)
        {
            if(data[j] > max && flag[j] == 0)
            {
                max = data[j];
                index = j;
            }
        }
        if(pre_max == max)
            order[index] = order[pre_index];
        else
            order[index] = i+1;
        pre_max = max;
        pre_index = index;
        //printf("index %d max %lf \n", index, max);
        flag[index] = 1;
    }
   /* for(int i = 0; i<N; i++)
        printf("%d ", order[i]);
*/
}

int main()
{
    int N, MM;
    char id[2001][8], tmp[8];
    double C[2001], M[2001], E[2001], A[2001];
    int c[2001], m[2001], e[2001], a[2001];
    scanf("%d%d", &N, &MM);
    for(int i = 0; i<N; i++)
    {
        scanf("%s%lf%lf%lf", id[i], C + i, M + i, E + i);
        A[i] = (C[i] + M[i] + E[i])/3;
        //printf("%lf %lf %lf %lf\n", C[i], M[i], E[i], A[i]);
    }
    get_order(c, C, N);
    get_order(m, M, N);
    get_order(e, E, N);
    get_order(a, A, N);
    for(int j = 0; j<MM; j++)
    {
        int i;
        scanf("%s", tmp);
        for(i = 0; i<N; i++)
        {
            if(strcmp(tmp, id[i]) == 0)
            {
               // printf("%s\n", id[i]);
                if(a[i] <= c[i] && a[i] <= m[i] && a[i] <= e[i])
                    printf("%d A\n", a[i]);   
                else if(c[i] <= m[i] && c[i] <= e[i] && c[i] <= a[i])
                    printf("%d C\n", c[i]);
                else if(c[i] > m[i] && m[i] <= e[i] && m[i] <= a[i])
                    printf("%d M\n", m[i]);
                else if(c[i] > e[i] && m[i] > e[i] && a[i] > e[i])
                    printf("%d E\n", e[i]);    
                break;
            }
        }
        if(i == N)
            printf("N/A\n");
    }
       
}