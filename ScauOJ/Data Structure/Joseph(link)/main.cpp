#include <iostream>
#include <list>
#include <vector>
#define LI list<int>
#define VI vector<int>

using namespace std;

LI cycle;
VI order;

void next_iter(LI::iterator &it)//����STL�е�˫������ģ���ѭ������̽�⵽iter������β��ʱ��ʹiterָ����ͷ
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
    int n,s,k;//n�����γɻ����ӵ�s���˿�ʼ��ÿ��k���˳��һ����
    int i;
    cycle.clear();
    order.clear();
    cin>>n>>s>>k;
    //����
    for(i=1;i<=n;i++)
        cycle.push_back(i);
    LI::iterator it,it2;
    //��λ����s����
    it = cycle.begin();
    for(i=0;i<s-1;i++)
        next_iter(it);
    //���ϳ��ˣ�ֱ�������
    while(!cycle.empty())
    {
        for(i=0;i<k-1;i++)
            next_iter(it);//ȡ��һ���˵�λ��
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
