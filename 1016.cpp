#include <stdio.h>
#include <string.h>

int main()
{
    int price[24];
    int N;
    char pre_name[20];
    double pre_count = -1;
    char list[1000][3][20] = {0};
    for(int i= 0; i<24; i++)
    {
        scanf("%d", price + i);
    }
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        int j;
        char t[3][20] = {0};
        scanf("%s%s%s", t[0], t[1], t[2]);
        if(i == 0)
        {
            strcpy(list[i][0], t[0]);
            strcpy(list[i][1], t[1]);
            strcpy(list[i][2], t[2]);
        }
        for(j = 0; j<i; j++)
        {
            if(strcmp(t[0], list[j][0]) < 0)
            {
              
                for(int k = i; k>j; k--)
                {
                    strcpy(list[k][0], list[k-1][0]);
                    strcpy(list[k][1], list[k-1][1]);
                    strcpy(list[k][2], list[k-1][2]);
                }
                
                strcpy(list[j][0], t[0]);
                strcpy(list[j][1], t[1]);
                strcpy(list[j][2], t[2]);
                break;
            }
            else if(strcmp(t[0], list[j][0]) == 0)
            {
              
                if(strcmp(t[1], list[j][1]) < 0)
                {
               
                    for(int k = i; k>j; k--)
                    {
                        strcpy(list[k][0], list[k-1][0]);
                        strcpy(list[k][1], list[k-1][1]);
                        strcpy(list[k][2], list[k-1][2]);
                    }
                    strcpy(list[j][0], t[0]);
                    strcpy(list[j][1], t[1]);
                    strcpy(list[j][2], t[2]);
                    break;
                }
                else
                    continue;
            }
        }
        if(j == i)
        {
            strcpy(list[j][0], t[0]);
            strcpy(list[j][1], t[1]);
            strcpy(list[j][2], t[2]);
        }

      /*  printf("\n");
        for(int ii = 0; ii<=i; ii++)
        {
            printf("%d %s %s %s\n", i, list[ii][0], list[ii][1], list[ii][2]);
        }
*/
    }
  
    for(int i = 0; i<N; i++)
    {
        
        if(strcmp(list[i][2], "off-line") == 0)
            continue;
        else
        {
            if(strcmp(list[i+1][0], list[i][0])==0  && strcmp(list[i][2], "on-line")==0 && strcmp(list[i+1][2], "off-line")==0)
            {
                double count = 0;
                int minute = 0;
                int day1, day2, h1, h2;
                int m1[24] = {0}, m2[24] = {0};
                if(strcmp(pre_name, list[i][0]) != 0)
                {
                    if(pre_count != -1)
                        printf("Total amount: $%.2f\n", pre_count);
                    printf("%s %c%c\n", list[i][0], list[i][1][0], list[i][1][1]);
                    pre_count = 0;
                }
                strcpy(pre_name, list[i][0]);
                day1 = (list[i][1][3] - '0') * 10 + list[i][1][4] - '0';
                day2 = (list[i+1][1][3] - '0') * 10 + list[i+1][1][4] - '0';
                h1 = (list[i][1][6] - '0') * 10 + list[i][1][7] - '0';
                h2 = (list[i+1][1][6] - '0') * 10 + list[i+1][1][7] - '0';
                for(int i = 0; i<h1; i++)
                {
                    m1[i] = 60;
                }
                m1[h1] = (list[i][1][9] - '0') * 10 + list[i][1][10] - '0';
                for(int i = 0; i<h2; i++)
                {
                    m2[i] = 60;
                }
                m2[h2] = (list[i+1][1][9] - '0') * 10 + list[i+1][1][10] - '0';
                printf("%02d:%02d:%02d ", day1, h1, m1[h1]);
                printf("%02d:%02d:%02d ", day2, h2, m2[h2]);

                for(int i =0; i<24; i++)
                {
                    minute += (day2 - day1) * 60 + m2[i] - m1[i];
                    count += (day2 - day1) * 60 * price[i] + m2[i] * price[i] - m1[i] * price[i];
                }
                pre_count += count/100;
                printf("%d $%.2f\n", minute, count/100);
            }

        }
    }
    if(pre_count != -1)
        printf("Total amount: $%.2f\n", pre_count);
}