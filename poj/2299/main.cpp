#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define VI vector<int>
#define N 5000010

typedef long long ll;
using namespace std;
int n,tree[N];

struct node{
    int num,index,rk;
};
bool cmpnum(node a,node b)
{
    return a.num<b.num;
}
bool cmpindex(node a,node b)
{
    return a.index<b.index;
}
node mes[N];

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int k)
{
    while(k<=n)
    {
        tree[k]++;
        k+=lowbit(k);
    }
}

int get(int k)
{
    int sum=0;
    while(k>0)
    {
        sum+=tree[k];
        k-=lowbit(k);
    }
    return sum;
}

void run()
{
    int i;
    ll ans;
    while(cin>>n,n!=0)
    {
        memset(tree,0,sizeof(tree));
        ans=0;
        for(i=0;i<n;i++)
        {
            cin>>mes[i].num;
            mes[i].index=i;
        }
        sort(mes,mes+n,cmpnum);
        for(i=0;i<n;i++)
            mes[i].rk=i+1;
        sort(mes,mes+n,cmpindex);
        for(i=0;i<n;i++)
        {
            ans+=i-get(mes[i].rk);
            add(mes[i].rk);
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    run();
    return 0;
}
/*
WA:ans should be longlong
AC
*/
