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
#define uu e[k].u
#define vv e[k].v
#define ww e[k].w
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 155;
const int M = 3005;
const int Q = 1005;
struct _edge
{
    int u,v,w;
    friend bool operator < (const _edge &a, const _edge &b)
    {
        return a.w<b.w;
    }
}e[M];
int n,m,q;
int dp[N][N][M];
bool vis[N],visxy[N][N];
int qx[Q],qy[Q],qz[Q];

void pre()
{
    sort(e,e+m);
    memset(dp,-1,sizeof(dp));
    int s,k,t;
    for(s=1;s<=n;++s)
    {
        if(!vis[s]) continue;
        dp[s][s][0]=0;
        for(k=0;k<m;++k)
        {
            for(t=0;t<=n;++t)
            {
                if(dp[s][uu][t]==-1) continue;
                if(dp[s][vv][t+1]==-1 || dp[s][vv][t+1]>dp[s][uu][t]+ww)
                    dp[s][vv][t+1] = dp[s][uu][t]+ww;
            }
        }
    }
    for(s=1;s<=n;++s)
    {
        if(!vis[s]) continue;
        for(k=1;k<=n;++k)
        {
            if(!visxy[s][k])    continue;
            for(t=1;t<=n;++t)
            {
                if(dp[s][k][t-1]!=-1 && (dp[s][k][t]==-1 || dp[s][k][t]>dp[s][k][t-1]))
                    dp[s][k][t]=dp[s][k][t-1];
            }
        }
    }
}

void run()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;++i)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    memset(vis,0,sizeof(vis));
    memset(visxy,0,sizeof(visxy));
    for(int i=0;i<q;++i)
        scanf("%d%d%d",&qx[i],&qy[i],&qz[i]), vis[qx[i]]=visxy[qx[i]][qy[i]]=1,qz[i]=min(qz[i],n);
    pre();
    for(int i=0;i<q;++i)
    {
        printf("%d\n",dp[qx[i]][qy[i]][qz[i]]);
    }
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
