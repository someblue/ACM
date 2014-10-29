#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef long long ll;

ll d[N][N];
int n;

struct _node{
    ll w;
    int u,v;
    friend bool operator < (const _node &a,const _node &b)
    {
        return a.w < b.w;
    }
}node[N*N];
int ncnt;

int fa[N];
inline int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

struct _edge{
    int from,to,next;
    ll w;
}edge[N*N];
int ecnt,head[N];

inline void addedge(int u,int v,ll w)
{
    edge[ecnt].from = u;
    edge[ecnt].to = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}
void showedge()
{
    for(int i=0;i<ecnt;i++)
        printf("%d %d %d %d\n",edge[i].from,edge[i].to,edge[i].w,edge[i].w);
}

bool vis[N];
ll ans[N][N];
void dfs(int u,int f)
{
    if(vis[u]) return;
    vis[u]=1;
}

void run()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%I64d",&d[i][j]);
    for(i=1;i<=n;i++)
        if(d[i][i])
    {
        puts("NO");
        return;
    }
    ncnt=0;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(d[i][j]!=d[j][i] || d[i][j]==0)
            {
                puts("NO");
                return;
            }
            node[ncnt].w=d[i][j];
            node[ncnt].u=i;
            node[ncnt].v=j;
            ncnt++;
        }
    for(i=1;i<=n;i++)
        fa[i]=i;
    sort(node,node+ncnt);
    memset(head,-1,sizeof(head));
    ecnt=0;
    for(i=0;i<ncnt;i++)
    {
//        cout<<node[i].u<<' '<<node[i].v<<' '<<node[i].w<<endl;
        int u = find(node[i].u);
        int v = find(node[i].v);
        if(u!=v)
        {
            addedge(node[i].u,node[i].v,node[i].w);
            addedge(node[i].v,node[i].u,node[i].w);
            fa[u]=v;
        }
    }
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    dfs(1,-1);
    puts("YES");
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
