#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,n) for(i=1;i<=(n);i++)
using namespace std;
const int INF = 1e9;
const int N = 1010;

struct Edge{
    int from,to,cap,flow;
};

struct ISAP{
    int n,m,s,t;
    int p[N],num[N];
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];
    int d[N],cur[N];
    void init(int _n,int _m)
    {
        n=_n; m=_m;
        int i;
        edges.clear();
        FOR(i,n)
        {
            G[i].clear();
            d[i]=INF;
        }
    }
    void AddEdge(int from,int to,int cap)
    {
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for(unsigned i=0;i<G[x].size();i++)
            {
                Edge& e = edges[G[x][i]^1];
                if(!vis[e.from] && e.cap>e.flow)
                {
                    vis[e.from]=1;
                    d[e.from] = d[x]+1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }
    int Augment()
    {
        int x=t, a=INF;
        while(x!=s)
        {
            Edge& e = edges[p[x]];
            a = min(a,e.cap-e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while(x!=s)
        {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;
            x=edges[p[x]].from;
        }
        return a;
    }
    int Maxflow(int _s,int _t)
    {
        s=_s; t=_t;
        int flow = 0, i;
        BFS();
        if(d[s]>=n) return 0;
        memset(num,0,sizeof(num));
        memset(p,0,sizeof(p));
        FOR(i,n) if(d[i]<INF) num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n)
        {
            if(x==t)
            {
                flow+=Augment();
                x=s;
            }
            int ok=0;
            for(unsigned i=cur[x];i<G[x].size();i++)
            {
                Edge& e=edges[G[x][i]];
                if(e.cap>e.flow && d[x]==d[e.to]+1)
                {
                    ok=1;
                    p[e.to]=G[x][i];
                    cur[x]=i;
                    x=e.to;
                    break;
                }
            }
            if(!ok)
            {
                int m=n-1;
                for(unsigned i=0;i<G[x].size();i++)
                {
                    Edge& e=edges[G[x][i]];
                    if(e.cap>e.flow) m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0) break;
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s) x=edges[p[x]].from;
            }
        }
        return flow;
    }
};

ISAP isap;

void run()
{
    int n,m,u,v,c;
    scanf("%d%d",&n,&m);
    isap.init(n,m);
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&c);
        isap.AddEdge(u,v,c);
        //isap.AddEdge(v,u,c);
    }
    static int cas = 1;
    printf("Case %d: %d\n",cas++,isap.Maxflow(1,n));
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
