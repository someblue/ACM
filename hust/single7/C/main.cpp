#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 50005;
const int mod = 300;

int fa[N],d[N];
int n,m;

void init()
{
    for(int i=1;i<=n;++i)
        fa[i]=i, d[i]=0;
}

int find(int x)
{
    //return fa[x]==x? x: fa[x]=find(fa[x]);
    if(fa[x]==x)
        return x;
    int u=find(fa[x]);
    d[x]+=d[fa[x]];
    fa[x] = u;
    return u;
}

bool equ(int a,int b)
{
    return (b-a)%mod == 0;
}

void run()
{
    init();
    int a,b,x;
    int ta,tb;
    int ans=0;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&x);
        ta = find(a);
        tb = find(b);
        if(ta!=tb)
        {
            fa[tb]=ta;
            d[tb]=d[a]-d[b]+x;
        }
        else
        {
            if(d[b]-d[a]!=x)
                ++ans;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
