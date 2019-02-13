#include <stdio.h>

struct QUEUE
{
    int customer[11];
    int head; 
    int tail;
    int tail_time;
    int size;
};


int N, M, K, Q, t;
int process[1005];
int start[1005] = {0};
int finish[1005] = {0};   
struct QUEUE queue[25];


void push(struct QUEUE *q, int index)
{
    q->customer[q->tail] = index;
    q->tail = (q->tail + 1) % M;
    start[index] = q->tail_time;
    q->tail_time = q->tail_time + process[index];
    finish[index] = q->tail_time;
    q->size ++;
   // for(int i = 0; i<11; i++)
    //    printf("%d ", q->customer[i]);
  //  printf("\n%d %d %d %d\n", q->head, q->tail, q->tail_time, q->size);
}

void pop(struct QUEUE *q)
{
    q->head = (q->head + 1) % M;
    q->size --;
}

void initQueue(struct QUEUE *q)
{
    for(int i = 0; i<11; i++)
        q->customer[i] = 0;
    q->head = 0; 
    q->tail = 0;
    q->size = 0;
    q->tail_time = 0;
}

int findQueue()
{
    int min = 9099, min_size = 9999, early = 9999, early_time = 9999;
    for(int i = 0; i<N; i++)
    {
        if(queue[i].size == 0)
            return i;
        if(queue[i].size < min_size)
        {
            min = i;
            min_size = queue[i].size;
        }
        if(finish[queue[i].customer[queue[i].head]] < early_time)
        {
            early = i;
            early_time = finish[queue[i].customer[queue[i].head]];
        }
    }

    if(min_size == M)
    {
        pop(queue + early);
        return early;
    }
    else
        return min;
}

void insertQueue(struct QUEUE *q, int order)
{
    int index = findQueue();
    //printf("find index %d \n", index);
    push(queue + index, order);
  //  printf("finish: ");
  //  for(int i = 1; i<=K; i++)
     //   printf("%d ",finish[i]);
}
int main(int argc, char const *argv[])
{
   

    scanf("%d%d%d%d", &N, &M, &K, &Q);
    struct QUEUE q[20];
    for(int i = 0; i<N; i++)
    {
        initQueue(q + i);
    }
    for(int i = 0; i<K; i++)
    {
        scanf("%d", process + i + 1);
        insertQueue(q, i + 1);
    }

    for(int i = 0; i<Q; i++)
    {
        scanf("%d", &t);
        if(start[t]<540)
        {
            printf("%02d:%02d\n", finish[t]/60+8, finish[t]%60);
        }
        else   
            printf("Sorry\n");
    }
    return 0;
}