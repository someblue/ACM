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
const int maxn = 1000;
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

Dinic dinic;
struct point{
    int l,r;
    point() {}
    point(int _l,int _r)
    {
        l=_l;
        r=_r;
    }
};
struct node{
    int s,e,w;
};
vector<int> v;
vector<point> p;
int n,m;
int start=0,terminal=999;
node task[210];

inline int id_task(int x)  {return x;}
inline int id_point(int x)  {return x+210+1;}

void run()
{
    cout<<n<<' '<<m<<endl;
    int i,j;
    int s,e,nn,t;
    dinic.init(terminal);
    v.clear();
    p.clear();
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&s,&nn,&e,&t);
        task[i].s=s;
        task[i].e=e;
        task[i].w=nn*t;
        v.push_back(s);
        v.push_back(e);
    }
    cout<<"read"<<endl; // DEBUG
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    int sz = v.size();
    p.push_back(point(v[0],v[0]));
    for(i=1;i<sz;i++)
    {
        if(v[i-1]+1<=v[i]-1)
            p.push_back(point(v[i-1]+1,v[i]-1));
        p.push_back(point(v[i],v[i]));
    }
    cout<<"pre"<<endl;  //DEBUG
    sz = p.size();
    for(i=1;i<=n;i++)
    {
        dinic.AddEdge(s,id_task(i),task[i].w);
        for(j=0;j<sz;j++)
            if(p[j].l>=task[i].s && p[j].r<=task[i].e)
                dinic.AddEdge(id_task(i),id_point(j),task[i].w);
    }
    for(i=0;i<sz;i++)
        dinic.AddEdge(id_point(i),t,m*(p[j].r-p[j].l+1));
    cout<<sz<<endl;
    cout<<dinic.edges.size()<<endl;
    cout<<"build"<<endl;  //DEBUG
    printf("%d\n",dinic.Maxflow(s,t));
    cout<<"ok"<<endl;
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
