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
            for(unsigned i=0;i<G[x].size();i++)
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
        for(int &i=cur[x];i<(int)G[x].size();i++)
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

int cnt[15];
int c[15];
int n,m;
int s=21,t=23,s2=22;
Dinic dinic;

//inline int id_people(int x)  {return x;}
//inline int id_planet(int x)  {return x+10;}

void run()
{
    memset(cnt,0,sizeof(cnt));
    int i,j,x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            cnt[j]+=x;
        }
    }
    for(i=0;i<m;i++)
        scanf("%d",&c[i]);
    dinic.init(t);
    for(i=0;i<m;i++)
    {
        dinic.AddEdge(s,i,cnt[i]);
        dinic.AddEdge(i,t,c[i]);
    }
    dinic.AddEdge(s2,s,n);
    if(dinic.Maxflow(s2,t)==n)  puts("Yes");
    else  puts("No");
//    printf("%d\n",dinic.Maxflow(s2,t));
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif // LOCAL
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
