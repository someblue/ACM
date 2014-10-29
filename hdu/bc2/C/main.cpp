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
const int N = 1005;

struct _node {
    int x,y;
    friend bool operator < (const _node a,const _node b)
    {
        return a.x<b.x;
    }
};
struct _edge{
    int to,next;
};

_edge edge[N*2];
int edgecnt,first[N];

inline void add_edge(int u,int v)
{
    edge[edgecnt].to = v;
    edge[edgecnt].next = first[u];
    first[u] = edgecnt++;
}

_node point[N];
int n,l;

inline bool dcmp(double x)
{
    if(abs(x) < eps)    return 0;
    return x<0? -1:1;
}

inline bool ok(int u,int v)
{
    double x1,y1,x2,y2;
    x1 = point[u].x;
    y1 = point[u].y;
    x2 = point[v].x;
    y2 = point[v].y;
    return dcmp((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) - (double)l*(double)l)<=0;
}

int d[N];
bool vis[N];
int bfs(int s,int t)
{
    memset(vis,0,sizeof(vis));
    queue<int> q;
    d[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int e=first[u];e!=-1;e=edge[e].next)
        {
            int &v=edge[e].to;
            if(vis[v]) continue;
            if(v == t)  return d[u];
            vis[v] = 1;
            d[v] = d[u]+1;
            q.push(v);
        }
    }
    return -1;
}

void run()
{
    int i,j;
    memset(first,-1,sizeof(first));
    edgecnt = 0;
    scanf("%d%d",&n,&l);
    scanf("%d%d",&point[0].x,&point[0].y);
    scanf("%d%d",&point[n+1].x,&point[n+1].y);
    for(i=1;i<=n;i++)
        scanf("%d%d",&point[i].x,&point[i].y);
    for(i=0;i<=n;++i)
        for(j=i+1;j<=n+1;++j)
            if(ok(i,j))
            {
                //cout<<"ok:  "<<i<<' '<<j<<endl;
                add_edge(i,j);
                add_edge(j,i);
            }
    int ans = bfs(0,n+1);
    if(ans == -1)   puts("impossible");
    else
        printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
