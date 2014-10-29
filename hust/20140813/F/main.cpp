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
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;
const int N = 310;
const int M = 50010;

struct _edge{
    int to,next,a,b,t;
}edge[M];
int first[N],edgecnt;
inline void add_edge(int u,int v,int a,int b,int t)
{
    edge[edgecnt].to = v;
    edge[edgecnt].a = a;
    edge[edgecnt].b = b;
    edge[edgecnt].t = t;
    edge[edgecnt].next = first[u];
    first[u] = edgecnt++;
}

int n,m,s,t;
int d[N];
bool vis[N];

void init()
{
    memset(first,-1,sizeof(first));
    edgecnt=0;
}

void read()
{
    int u,v,a,b,t;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
        if(t>a) continue;
        add_edge(u,v,a,b,t);
    }
}
int dij()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i)   d[i]=INF;
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(d[s],s));
    while(!q.empty())
    {
        int u = q.top().second; q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int e=first[u];e!=-1;e=edge[e].next)
        {
            int &v = edge[e].to;
            int tt=d[u]%(edge[e].a+edge[e].b);
            if(tt>edge[e].a-edge[e].t)tt=edge[e].a+edge[e].b-tt;
            else tt=0;
            int tmp = d[u]+tt+edge[e].t;

            if(d[v] > tmp)
            {
                d[v] = tmp;
                q.push(make_pair(tmp,v));
            }
        }
    }
    return d[t];
}

void run()
{
    init();
    read();
    static int cas = 1;
    printf("Case %d: %d\n",cas++,dij());
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
        run();
    return 0;
}

/*
Sample Input
3 2 1 3
1 2 5 6 3
2 3 7 7 6
3 2 1 3
1 2 5 6 3
2 3 9 5 6
Sample Output
Case 1: 20
Case 2: 9
*/
