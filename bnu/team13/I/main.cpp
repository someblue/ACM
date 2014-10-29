#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 10010;

struct _edge
{
    int v,next;
};
_edge edge[N*2];
int first[N],n,ecnt;
int dp[N][2];
int cost[5];

inline void add(int u,int v)
{
    edge[ecnt].v = v;
    edge[ecnt].next = first[u];
    first[u] = ecnt++;
}

void dfs(int u,int fa)
{
    dp[u][0] = dp[u][1] = INF;
    int num = 0;
    int sum1,sum0,dmx,dmx2,sum3;
    sum1=sum0=0;
    sum3=0;
    dmx=dmx2=0;
    for(int e=first[u]; e!=-1; e=edge[e].next)
    {
        int v = edge[e].v;
        if(v==fa) continue;

        num++;
        dfs(v,u);
        sum1 += dp[v][1];
        sum0 += dp[v][0];
        sum3 += min(dp[v][1],dp[v][0]);
        int d = dp[v][1]-dp[v][0];
        if(d>dmx2)
        {
            dmx2 = d;
            if(dmx2 > dmx)
            {
                swap(dmx,dmx2);
            }
        }
    }

    if(num==0)
    {
        dp[u][0]=0;
        dp[u][1]=cost[1];
    }
    else if(num==1)
    {
        dp[u][0] = min(sum0 + cost[1], sum1);
        dp[u][1] = min(sum0 + cost[2], sum1 + cost[1]);
    }
    else
    {
        dp[u][0] = min(sum1 - dmx + cost[1] , sum1);
        dp[u][0] = min(dp[u][0], sum1 - dmx - dmx2 + cost[2]);
        dp[u][1] = min(sum3 + cost[3], sum1 + cost[1]);
        dp[u][1] = min(dp[u][1], sum1 - dmx + cost[2]);
    }

//    if(flag)
//    {
//        dp[u][0]=0;
//        dp[u][1]=cost[1];
//        return;
//    }
//    dp[u][0] = min(sum1 - dmx + cost[1],sum1 - dmx - dmx2 + cost[2]);
//    dp[u][0] = min(dp[u][0],sum1);
//// sum1 - dmx + cost[1],
//// sum1 - dmx1 - dmx2 + cost[2],
//    dp[u][1] = min(min(sum1 + cost[1],sum1 - dmx + cost[2]),sum0 + cost[3]);
//// sum1 + cost[1];
//// sum1 - dmx + cost[2],
//// sum0 + cost[3];
}

void run()
{
    memset(first,-1,sizeof(first));
    ecnt=0;
    scanf("%d",&n);
    int u,v;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(0,-1);
// for(int i=0;i<n;i++)
// {
//// printf("%d: %d %d\n",i,dp[i][0],dp[i][1]);
// }
    printf("$%d\n",min(dp[0][0],dp[0][1]));
}

int main()
{
//freopen("in","r",stdin);
    cost[1]=100;
    cost[2]=175;
    cost[3]=500;
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
