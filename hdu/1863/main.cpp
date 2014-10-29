#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 110
#define M 6000
using namespace std;
typedef vector<int> VI;
typedef long long ll;

struct _node{
    int u,v,w;
    friend bool operator < (_node a,_node b)
    {
        return a.w<b.w;
    }
};
_node l[M];
int fa[N];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void run()
{
    int n,m,ans,rootnum;
    int i,j,u,v,w;
    while(scanf("%d%d",&m,&n)!=EOF&&m!=0)
    {
        for(i=1;i<=n;i++) fa[i]=i;
        ans=rootnum=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&l[i].u,&l[i].v,&l[i].w);
        }
        sort(l,l+m);
        for(i=0;i<m;i++)
        {
            u = l[i].u;  v = l[i].v;
            u = find(u); v = find(v);
            if(u!=v)
            {
                fa[u]=v;
                ans+=l[i].w;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(fa[i]==i)
            {
                rootnum++;
                if(rootnum>1) break;
            }
        }
        if(rootnum>1) printf("?\n");
        else printf("%d\n",ans);
    }
}

int main()
{
    run();
    return 0;
}
