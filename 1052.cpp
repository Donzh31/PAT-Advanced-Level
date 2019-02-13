#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Node{
    int value;
    int next;
};
struct List{
    int address;
    int value;
} list[100005];
bool cmp(const struct List &a, const struct List &b)
{
    return a.value < b.value;
}
map <int, struct Node> L;
int main()
{
    int N,start;
    cin >> N >> start;
    int address, value, next;
    for(int i = 0; i<N; i++)
    {
        scanf("%d%d%d", &address, &value, &next); 
        L[address].value = value;
        L[address].next = next;
    }
    int cnt = 0;
    while(start != -1)
    {
        list[cnt].address = start;
        list[cnt].value = L[start].value;
        start = L[start].next;
        cnt ++;
    }
    sort(list, list + cnt, cmp);
    if(cnt != 0)
        printf("%d %05d\n", cnt, list[0].address);
    else
        printf("0 -1");
    for(int i = 0; i<cnt-1; i++)
    {
        printf("%05d %d %05d\n", list[i].address, list[i].value, list[i+1].address);
    }
    if(cnt != 0)
        printf("%05d %d -1\n", list[cnt-1].address, list[cnt-1].value);

}