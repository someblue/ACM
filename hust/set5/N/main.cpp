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
const int N = 10000;
int fa[N],sum[N],t[N];
int n,m;
int find(int x)
{
    if(fa[x]==x)
        return x;
    else
    {
        int tmp=find(fa[x]);
        t[x]+=t[fa[x]];
        return fa[x]=tmp;
    }
}

void run()
{
    static int cas = 1;
    printf("Case %d:\n",cas++);
    char s[5];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i,sum[i]=1,t[i]=0;
    int u,v;
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='T')
        {
            scanf("%d%d",&u,&v);
            u=find(u);
            v=find(v);
            if(u!=v)
            {
                fa[u]=v;
                sum[v]+=sum[u];
                t[u]++;
            }
        }
        else
        {
            scanf("%d",&u);
            v=find(u);
            printf("%d %d %d\n",v,sum[v],t[u]);
        }
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
