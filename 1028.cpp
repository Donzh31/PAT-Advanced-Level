#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Stu{
    int id;
    char name[10];
    int grade;
}stu[100000];

bool cmp1(struct Stu &a, struct Stu &b)
{
    return a.id<b.id;
}
bool cmp2(struct Stu &a, struct Stu &b)
{
    if(strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else
        return a.id < b.id;
}

bool cmp3(struct Stu &a, struct Stu &b)
{
    if(a.grade != b.grade)
        return a.grade < b.grade;
    else
        return a.id < b.id;
}

int main()
{
    int N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++)
    {
        scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].grade);
    }
    if(C == 1)
        sort(stu, stu+N, cmp1);
    else if(C == 2)
        sort(stu, stu+N, cmp2);
    else if(C == 3)
        sort(stu, stu+N, cmp3);
    for(int i=0; i<N; i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    return 0;
}