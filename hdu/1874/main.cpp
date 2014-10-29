#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 210
#define M 2010
#define INF 1e8
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int first[M],u[M],v[M],w[M],next[M];
int d[M];

void run()
{
    int a,b;
    while(cin>>n>>m)
//    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        //memset(first,-1,sizeof(first));
        for(i=0;i<n;i++) first[i]=-1;
        for(i=0;i<m;i++)
        {
            cin>>u[i]>>v[i]>>w[i];
//            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            next[i] = first[u[i]];
            first[u[i]] = i;

            u[i+m] = v[i];
            v[i+m] = u[i];
            w[i+m] = w[i];

            next[i+m] = first[u[i+m]];
            first[u[i+m]] = i+m;
        }
        cin>>a>>b;
//        scanf("%d%d",&a,&b);
        priority_queue<pii,vector<pii>,greater<pii> > q;
        for(i=0;i<n;i++) d[i]=(i==a)?0:INF;
        q.push(make_pair(d[a],a));
        while(!q.empty())
        {
            pii u = q.top(); q.pop();
            int x = u.second;
            if(u.first!=d[x]) continue;
            int e;
            for(e=first[x];e!=-1;e=next[e])
                if(d[v[e]]>d[x]+w[e])
                {
                    d[v[e]] = d[x]+w[e];
                    q.push(make_pair(d[v[e]],v[e]));
                }
        }
        if(d[b]==INF)
//            printf("-1\n");
            cout<<"-1"<<endl;
        else
//            printf("%d\n",d[b]);
            cout<<d[b]<<endl;
    }
}

int main()
{
    freopen("in","r",stdin);
    ios::sync_with_stdio(0);
    run();
    return 0;
}
