#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define N 505
#define M 25005
using namespace std;

struct _node{
    int u,v,w;
    friend bool operator < (const _node a,const _node b)
    {
        return a.w<b.w;
    }
};

_node edge[M];
int fa[N];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline int readint()
{
    char c; int res=0;
    c=getchar();
    while(!isdigit(c))  c=getchar();
    while(isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void run()
{
    int n,m,k;
    int i,t,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)   fa[i]=i;
    for(i=0;i<m;++i)
    {
//        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        edge[i].u=readint();
        edge[i].v=readint();
        edge[i].w=readint();
    }
    for(i=0;i<k;++i)
    {
//        scanf("%d",&t);
        t=readint();
//        scanf("%d",&a);
        a=readint();
        t--;
        while(t--)
        {
//            scanf("%d",&b);
            b=readint();
            a=find(a);
            b=find(b);
            if(a!=b)    fa[a]=b;
            a=b;
        }
    }
//    for(i=1;i<=n;++i)   cout<<fa[i]<<' ';
//    cout<<endl;
    int cnt=0;
    for(i=0;i<m;++i)
    {
        a=find(edge[i].u);
        b=find(edge[i].v);
        if(a==b)    continue;
        edge[cnt++]=edge[i];
    }
    m=cnt;
    sort(edge,edge+m);
    int ans=0;
    for(i=0;i<m;++i)
    {
        a=find(edge[i].u);
        b=find(edge[i].v);
        if(a==b)    continue;
        fa[a]=fa[b];
        ans+=edge[i].w;
    }
    for(i=2;i<=n;++i)   if(find(i)!=find(i-1))  {puts("-1");return;}
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
