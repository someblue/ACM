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
const int N = 1010;

char s[7][N];
int cost[N][5];
int dp[N][1<<5];
int st[1<<5],top;
int n;
bool vis[1<<5];

void init()
{
    top=0;
    int t;
    for(int i=1;i<(1<<5);++i)
    {
        t=0;
        for(int j=0;j<5;++j)
            if((1<<j)&i)
                t++;
        if(t==3)
            st[top++]=i;
    }
}

void pre()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<5;++j)
            if(s[j][i]=='@')
                cost[i][j]=-1;
            else cost[i][j]=s[j][i]-'0';
}

int cal(int col,int sta)
{
    int res=0;
    for(int i=0;i<5;++i)
        if(st[sta] & (1<<i))
            res+=cost[col][i];
    return res;
}

bool ok(int from,int to)
{
    if(vis[to]) return 0;

}

void dfs(int col,int sta)
{
    for(int i=0;i<top;++i)
    {
        if(i==sta) continue;
        if(ok(sta,i))
            dp[col][i] = dp[col][sta] + cal(sta,i),
            vis[i]=1;
        dfs(col,i);
    }
}

void run()
{
    int i,j,t;
    for(i=0;i<5;++i)
        scanf("%s",s[i]);
    pre();
    for(i=0;i<n;++i)
        for(j=0;j<top;++j)
            dp[i][j]=INF;
    for(i=0;i<top;++i)
    {
        for(j=0;j<5;++j)
        {
            if(cost[0][j]!=-1)  continue;
            if((st[i]&(1<<j))==0)   break;
        }
        if(j==5)
        {
            dp[0][i]=0;
            memset(vis,0,sizeof(vis));
            dfs(0,i);
            break;
        }
    }
    for(int k=1;k<n;++k)
    {
        for(i=0;i<top;++i)
        {
            dp[k][i]=dp[k-1][i]+cal(k,i);
            memset(vis,0,sizeof(vis));
            dfs(k,i);
        }
    }
    int ans=INF;
    for(i=0;i<top;++i)
        ans = min(ans,dp[n-1][i]);
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    init();
    while(scanf("%d",&n)!=EOF && n)
        run();
    return 0;
}
