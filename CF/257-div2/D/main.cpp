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
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const ll INF=1LL<<60;
const double eps=1e-6;

int n,m,k;
int first[N];
int u[N],v[N],next[N];
ll w[N];
ll train[N];
int traincnt[N];

void read()
{
    scanf("%d%d%d",&n,&m,&k);
    ll t;
    int idx;
    for(int i=0;i<=n;i++)    first[i]=-1;
    for(int e=0;e<m;e++)
    {
        scanf("%d%d%I64d",&u[e],&v[e],&w[e]);
        next[e]=first[u[e]];
        first[u[e]]=e;

        int ne=e+m;
        u[ne]=v[e];
        v[ne]=u[e];
        w[ne]=w[e];
        next[ne]=first[u[ne]];
        first[u[ne]]=ne;
    }
    for(int i=0;i<=n;i++)   train[i]=INF,traincnt[i]=0;
    for(int i=0;i<k;i++)
    {
        scanf("%d%I64d",&idx,&t);
        train[idx]=min(train[idx],t);
        traincnt[idx]++;
    }
}

int ans;
bool done[N];
ll d[N];

void dij()
{
    priority_queue<pii,vector<pii>,greater<pii> > q;
    d[1]=0;
    for(int i=2;i<=n;i++)   d[i]=INF;
    memset(done,0,sizeof(done));
    q.push(make_pair(d[1],1));
    while(!q.empty())
    {
        pii u=q.top(); q.pop();
        int x=u.second;
        if(done[x]) continue;
        done[x]=1;
        if(traincnt[x])
        {
            if(d[x]<=train[x])  ans+=traincnt[x];
            else    d[x]=train[x],ans+=traincnt[x]-1;
        }
        for(int e=first[x];e!=-1;e=next[e]) if(d[v[e]]> d[x]+w[e])
        {
            d[v[e]]=d[x]+w[e];
            q.push(make_pair(d[v[e]],v[e]));
        }
    }
}

void run()
{
    read();
    ans=0;
    dij();
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
