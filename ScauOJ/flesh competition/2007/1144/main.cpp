#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define NN 1000000

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
int tree[NN+10];

inline int lowbit(int x)
{
    return x&(-x);
}

int sum(int x)
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

void add(int x)
{
    if(!x){tree[0]++;return;}
    while(x<=NN)
    {
        tree[x]++;
        x += lowbit(x);
    }
}

void cntlevel(const int n)
{
    int i;
    sort(star,star+n);
    for(i=0;i<n;i++)
    {
        star[i].level = sum(star[i].y);
        add(star[i].y);
    }
    sort(star,star+n,cmpId);
}

void run()
{
    memset(star,0,sizeof(star));
    memset(tree,0,sizeof(tree));
    int i,t,n,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&star[i].x,&star[i].y);
        star[i].id = i;
    }
    cntlevel(n);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        printf("%d\n",star[t-1].level);
    }
}

int main()
{
    run();
    return 0;
}
