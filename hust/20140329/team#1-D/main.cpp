#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 50010
#define M 500010
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef pair<ll,int> pli;
const ll INF = 1LL<<62;

struct _road{
    int u,v;
    ll w;
    friend bool operator < (_road a,_road b)
    {
        return a.w>b.w;
    }
};

ll t[N],d[N],d2[N];
_road r[M],r2[M];

int first[N],next[M],L[N];
int first2[N],next2[M];

void run()
{
    //cout<<INF<<endl;
    int _;
    scanf("%d",&_);
    int n,m,s,l;
    int i,e;
    int u,v; ll w;
    ll ans;
    bool flag;
    while(_--)
    {
        memset(first,-1,sizeof(first));
        memset(first2,-1,sizeof(first2));
        for(i=1;i<=n;i++) d[i]=d2[i]=INF;
        scanf("%d%d%d%d",&n,&m,&s,&l);
        d[s]=d2[s]=0;
        for(i=0;i<l;i++) scanf("%d",&L[i]);
        for(i=1;i<=n;i++) scanf("%lld",&t[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            w+=t[u];
            r[i].u=u;
            r[i].v=v;
            r[i].w=w;
            next[i]=first[u];
            first[u]=i;
            r2[i].u=v;
            r2[i].v=u;
            r2[i].w=w;
            next2[i]=first2[v];
            first2[v]=i;
        }
        priority_queue<pli,vector<pli>,greater<pli> > q,q2;
//        priority_queue<pli> q,q2;
        q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            pli p=q.top(); q.pop();
            int x=p.second;
            if(p.first!=d[x]) continue;
            for(e=first[x];e!=-1;e=next[e])
                if(d[r[e].v]>d[r[e].u]+r[e].w)
                {
                    d[r[e].v] = d[r[e].u]+r[e].w;
                    q.push(make_pair(d[r[e].v],r[e].v));
                }
        }
        q2.push(make_pair(d2[s],s));
        while(!q2.empty())
        {
            pli p=q2.top(); q2.pop();
            int x=p.second;
            if(p.first!=d2[x]) continue;
            for(e=first2[x];e!=-1;e=next2[e])
                if(d2[r2[e].v]>d2[r2[e].u]+r2[e].w)
                {
                    d2[r2[e].v] = d2[r2[e].u]+r2[e].w;
                    q.push(make_pair(d2[r2[e].v],r2[e].v));
                }
        }
        ans=0;flag=0;
        for(i=0;i<l;i++)
        {
            if(d[L[i]]==INF||d2[L[i]]==INF) {flag=1;break;}
            ans+=d[L[i]]+d2[L[i]];
        }
        if(flag) printf("Tumblerful\n");
        else printf("%lld\n",ans);
        //print d
        for(i=1;i<=n;i++) cout<<d[i]<<' ';  cout<<endl;
        for(i=1;i<=n;i++) cout<<d2[i]<<' ';  cout<<endl;
        //print adj list
        for(i=1;i<=n;i++)
        {
            cout<<i<<": ";
            for(e=first[i];e!=-1;e=next[e]) cout<<e<<' '<<r[e].u<<' '<<r[e].v<<' '<<r[e].w<<endl;

        }
        for(i=1;i<=n;i++)
        {
            cout<<i<<": ";
            for(e=first2[i];e!=-1;e=next2[e]) cout<<e<<' '<<r2[e].u<<' '<<r2[e].v<<' '<<r2[e].w<<endl;
        }

    }
}

int main()
{
    freopen("in","r",stdin);
    //ios::sync_with_stdio(0);
    run();
    return 0;
}
