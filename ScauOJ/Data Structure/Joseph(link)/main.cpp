#include <iostream>
#include <list>
#include <vector>
#define LI list<int>
#define VI vector<int>

using namespace std;

LI cycle;
VI order;

void next_iter(LI::iterator &it)//利用STL中的双向链表模拟成循环链表，探测到iter等于链尾的时候，使iter指向链头
{
    it++;
    if(it == cycle.end()) it = cycle.begin();
}

void print_order()
{
    unsigned int i;
    for(i=0;i!=order.size();i++)
        cout<<order[i]<<' ';
    cout<<endl;
}

void run()
{
    int n,s,k;//n个人形成环，从第s个人开始，每隔k个人抽出一个人
    int i;
    cycle.clear();
    order.clear();
    cin>>n>>s>>k;
    //建环
    for(i=1;i<=n;i++)
        cycle.push_back(i);
    LI::iterator it,it2;
    //定位到第s个人
    it = cycle.begin();
    for(i=0;i<s-1;i++)
        next_iter(it);
    //不断抽人，直到链表空
    while(!cycle.empty())
    {
        for(i=0;i<k-1;i++)
            next_iter(it);//取下一个人的位置
        order.push_back(*it);
        it2=it;
        next_iter(it);
        cycle.erase(it2);
    }
    print_order();
}

int main()
{
    run();
    return 0;
}
