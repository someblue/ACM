#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int maxn = 2000;
int cas = 1;

struct Edge{
    int from,to,cap,flow;
    Edge() {}
    Edge(int a,int b,int c,int d)
    {
        from=a,to=b,cap=c,flow=d;
    }
};

struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void AddEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    void init(int x)
    {
        memset(d,0,sizeof(d));
        edges.clear();
        for(int i=0;i<=x;i++)
            G[i].clear();
    }
    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front(); Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge &e = edges[G[x][i]];
                if(!vis[e.to] && e.cap>e.flow)
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a)
    {
        if(x==t || a==0) return a;
        int flow = 0, f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            Edge &e=edges[G[x][i]];
            if(d[x]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t)
    {
        this->s=s; this->t=t;
        int flow = 0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
};

Dinic dinic;
int n,m,d;
char g1[25][25],g2[25][25];
inline int id_p(int x,int y)  {return (x*m+y)*2;}
inline int id_l(int x,int y)  {return x*m+y+1000;}
inline bool inside(int x,int y)  {return x>=1 && x<=n && y>=1 && y<=m;}
int s = 0, t = 1999;
inline bool canout(int i,int j)
{
//    cout<<i<<' '<<j<<endl;
    for(int x=i-d;x<=i+d;x++)
        for(int y=j-d;y<=j+d;y++)
    {
        if(abs(x-i)+abs(y-j)>d || (x==i && y==j)) continue;
        if(!inside(x,y)) return 1;
    }
    return 0;
}
void run()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%s",g1[i]+1);
    for(int i=1;i<=n;i++)
        scanf("%s",g2[i]+1);
    m=strlen(g1[1]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            g1[i][j]-='0';
    dinic.init(t);
    int sum = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(g1[i][j]==0) continue;
            int u1 = id_p(i,j);
            int u2 = u1^1;
            dinic.AddEdge(u1,u2,g1[i][j]);
            for(int x=i-d;x<=i+d;x++)
                for(int y=j-d;y<=j+d;y++)
            {
                if(abs(x-i)+abs(y-j)>d || (x==i && y==j)) continue;
                if(!inside(x,y))
                {
                    dinic.AddEdge(u2,t,g1[i][j]);
                    goto bk;
                }
                else
                {
                    dinic.AddEdge(u2,id_p(x,y),g1[i][j]);
                }
            }
            bk:;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(g2[i][j]!='L')  continue;
            if(g1[i][j]==0 && canout(i,j))  continue;
            sum++;
            dinic.AddEdge(s,id_l(i,j),1);
            dinic.AddEdge(id_l(i,j),id_p(i,j),1);
        }
    int ans = sum - dinic.Maxflow(s,t);
    printf("Case #%d: ",cas++);  //cout<<sum<<' ';
    if(ans==0)  puts("no lizard was left behind.");
    else if(ans==1)  puts("1 lizard was left behind.");
    else printf("%d lizards were left behind.\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
