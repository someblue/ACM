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
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,n) for(i=1;i<=(n);++i)
#define N 105
using namespace std;
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;

struct _edge{
    int to,next;
    _edge(int a,int c) : to(a),next(c) {}
};

vector<_edge> edge;
int first[N];
pii road[3005];

void add_edge(int u, int v)
{
    edge.push_back(_edge(v,first[u]));
    first[u]=edge.size()-1;
}

int n,m;
int sum[N],allsum;

int d[N];
bool vis[N];

void bfs(int u,int v=-2)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(d,-1,sizeof(d));
//    for(int i=1;i<=n;++i)    d[i]=INF;
    d[u]=0;
    vis[u]=1;
    q.push(u);
    while(!q.empty())
    {
        int x=q.front();    q.pop();
        for(int e=first[x];e!=-1;e=edge[e].next)
        {
            int &y=edge[e].to;
            if(e==v*2 || e==v*2+1)    continue;
            if(vis[y])  continue;
            vis[y]=1;
            d[y]=d[x]+1;
            q.push(y);
        }
    }
}

int count_sum()
{
    int res=0,i;
    FOR(i,n)
    {
        if(d[i]==-1)   return -1;
        res+=d[i];
    }
    return res;
}

void show()
{
    for(int i=1;i<=n;++i)   cout<<d[i]<<' ';
    cout<<endl;
}

void run()
{
    int i;
    memset(first,-1,sizeof(first));
    REP(i,m)
    {
        scanf("%d%d",&road[i].first,&road[i].second);
        add_edge(road[i].first,road[i].second);
        add_edge(road[i].second,road[i].first);
    }
    //puts("---------read finish---------");
    allsum=0;
    bool flag=0;
    FOR(i,n)
    {
        bfs(i);//printf("%d: bfs ok!\n",i);
        //show();
        sum[i]=count_sum();
        if(sum[i]==-1)  {flag=1;break;}
        allsum+=sum[i];
    }
    //puts("--------sum finish---------");
    REP(i,m)
    {
        //printf("--------del: %d -> %d---------\n",road[i].first,road[i].second);
        int &u=road[i].first;
        int &v=road[i].second;
        if(flag)    {puts("INF");continue;}

        bfs(u,i);//show();
        int sumu=count_sum();
        if(sumu==-1)    {puts("INF");continue;}

        bfs(v,i);//show();
        int sumv=count_sum();
        if(sumv==-1)    {puts("INF");continue;}

        printf("%d\n",allsum+sumu+sumv-sum[u]-sum[v]);
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
