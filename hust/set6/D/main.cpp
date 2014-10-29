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
#define N 205
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
typedef pair<int,int> pii;

struct _edge{
    int to,w,next;
    _edge(int a,int b,int c) : to(a),w(b),next(c) {}
    friend bool operator < (const _edge a, const _edge b)
    {
        return a.w<b.w;
    }
};

vector<_edge> edge;
int first[N],d[N];
bool vis[N];
int n,m;

void dij(int s)
{
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;++i)    d[i]=INF;
    d[s]=0;
    q.push(make_pair(d[s],s));
    while(!q.empty())
    {
        pii u=q.top(); q.pop();
        int x=u.second;
        if(vis[x])  continue;
        vis[x]=1;
        for(int e=first[x];e!=-1;e=edge[e].next)
            if(d[edge[e].to] > d[x]+edge[e].w)
            {
                d[edge[e].to] = d[x]+edge[e].w;
                q.push(make_pair(d[edge[e].to],edge[e].to));
            }
    }
}

void add_edge(int u, int v,int w)
{
    edge.push_back(_edge(v,w,first[u]));
    first[u]=edge.size()-1;
}


void run()
{
    int s,t;
    int a,b,c;
    int i;
    memset(first,-1,sizeof(first));
    for(i=0;i<m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    scanf("%d%d",&s,&t);
    dij(s);
    if(d[t]==INF)   cout<<"-1"<<endl;
    else            cout<<d[t]<<endl;
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
