#include <iostream>
#include <algorithm>

using namespace std;

struct Stu{
    string name;
    string ID;
    int grade;
}male[1000], female[1000];

bool cmp1(const struct Stu &s1, const struct Stu &s2)
{
    return s1.grade < s2.grade;
}
bool cmp2(const struct Stu &s1, const struct Stu &s2)
{
    return s1.grade > s2.grade;
}

int main()
{
    int N;
    cin >> N;
    string tname;
    string kind;
    string tid;
    int tgrade;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<N; i++)
    {
        cin >> tname >> kind >> tid >> tgrade;
        if(kind == "F")
        {
            female[cnt1].name = tname;
            female[cnt1].ID = tid;
            female[cnt1].grade = tgrade;
            cnt1++;
        }
        else
        {
            male[cnt2].name = tname;
            male[cnt2].ID = tid;
            male[cnt2].grade = tgrade;
            cnt2++;
        }
    }
    sort(female, female + cnt1, cmp2);
    sort(male, male+cnt2, cmp1);
    if(cnt1 == 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << female[0].name << " " << female[0].ID << endl;
    }
     if(cnt2 == 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << male[0].name<< " " << male[0].ID << endl;
    }
    if(cnt1 == 0 || cnt2 == 0)
    {
        cout << "NA" << endl;
    }
    else
        cout << female[0].grade - male[0].grade << endl;
}