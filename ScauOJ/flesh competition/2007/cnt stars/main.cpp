#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define NN 100000

using namespace std;

struct node{
    int x,y,id,level;
    friend bool operator < (node a,node b)
    {
        return a.x<b.x||(a.x==b.x&&a.y<b.y);
    }
};
bool cmpId(node a,node b)
{
    return a.id<b.id;
}

node star[N];
int tree[N],maxx;

inline int lowbit(int x)
{
    return x&(-x);
}

inline int sum(int x)
{
    if(!x) return tree[0];
    int res=0;
    while(x>0)
    {
        res += tree[x];
        x -= lowbit(x);
    }
    return tree[0]+res;
}

inline void add(int x)
{
    if(!x){tree[0]++;return;}
    while(x<=maxx)
    {
        tree[x]++;
        x += lowbit(x);
    }
}

//void printstar(const int n)
//{
//    int i;
//    printf("------------------------\n");
//    printf("id\tx\ty\tlevel\n");
//    for(i=0;i<n;i++)
//        printf("%d\t%d\t%d\t%d\n",star[i].id,star[i].x,star[i].y,star[i].level);
//    printf("------------------------\n");
//}

void cntlevel(const int n)
{
    int i;
    sort(star,star+n);
    //printstar(n);
    for(i=0;i<n;i++)
    {
        star[i].level = sum(star[i].y);
        add(star[i].y);
    }
    //printstar(n);
    sort(star,star+n,cmpId);
    //printstar(n);
}

void run()
{
    memset(star,0,sizeof(star));
    memset(tree,0,sizeof(tree));
    maxx=0;
    int i,t,n,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>star[i].x>>star[i].y;
        star[i].id = i;
        if(star[i].y>maxx) maxx=star[i].y;
    }
    cntlevel(n);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>t;
        cout<<star[t-1].level<<endl;
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    ios::sync_with_stdio(0);
    run();
    return 0;
}
