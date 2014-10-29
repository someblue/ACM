#include <bits/stdc++.h>
#define N 12010

using namespace std;
int fa[N];

struct _node{
    int u,v,w;
};

    inline bool cmp1(_node a,_node b)
    {
        return a.w<b.w;
    }
    inline bool cmp2(_node a,_node b)
    {
        return a.w>b.w;
    }

_node node[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void run()
{
    int _,cas=1;
    int n,i,j,cnt,ans,a,b;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        cnt=ans=0;
        while(scanf("%d%d%d",&node[cnt].u,&node[cnt].v,&node[cnt].w),!(node[cnt].u==0 && node[cnt].v==0 && node[cnt].w==0)) cnt++;

        sort(node,node+cnt,cmp1);
        for(i=0;i<=n;i++) fa[i]=i;
        for(i=0;i<cnt;i++)
        {
            if((a=find(node[i].u))!=(b=find(node[i].v)))
            {
                ans+=node[i].w;
                fa[a] = b;
            }
        }

        sort(node,node+cnt,cmp2);
        for(i=0;i<=n;i++) fa[i]=i;
        for(i=0;i<cnt;i++)
        {
            if((a=find(node[i].u))!=(b=find(node[i].v)))
            {
                ans+=node[i].w;
                fa[a] = b;
            }
        }

        if(ans&1) printf("Case %d: %d/2\n",cas++,ans);
        else printf("Case %d: %d\n",cas++,ans/2);
    }
}

int main()
{
    run();
    return 0;
}
