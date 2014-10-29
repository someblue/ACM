#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

struct _node{
    int pos,val,ans;
    friend bool operator < (const _node &a, const _node &b)
    {
        return a.val < b.val;
    }
};
int n,m;
int fa[N],sum[N],b[N],mxval;
_node a[N];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void un(int u,int v)
{
    u=find(u), v=find(v);
    fa[u]=v;
    sum[v]+=sum[u];
}

void pre()
{
    memset(sum,0,sizeof(sum));
    mxval = -INF-10;
    for(int i=0;i<n;i++) fa[i]=i;
    for(int i=0;i<n;i++)
    {
        a[i].val=b[i],a[i].pos=i;
        if(a[i].val > mxval) mxval = a[i].val;
    }
    sort(a,a+n);
    int mx = 0;
    for(int i=n-1;i>=0;i--)
    {
        sum[a[i].pos]=1;
        if(sum[a[i].pos-1]) un(a[i].pos-1,a[i].pos);
        if(sum[a[i].pos+1]) un(a[i].pos+1,a[i].pos);
        if(mx < sum[find(a[i].pos)]) mx = sum[fa[a[i].pos]];
        a[i].ans = mx;
    }
}

int solve(int x)
{
    _node t;
    t.val=x;
    int id = lower_bound(a,a+n,t) - a;
    return a[id].ans;
}

void run()
{
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    pre();
    int x,y,op;
    while(m--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            if(x>mxval) puts("0");
            else printf("%d\n",solve(x));
        }
        else
        {
            scanf("%d%d",&y,&x);
            b[y-1]=x;
            pre();
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
