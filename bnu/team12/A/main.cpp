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
#define set(s,x) (s|=(1<<x))
#define test(s,x) (s&(1<<x))
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 35;

int cost[N][N];
int k,n,m;
bool vis[N];

bool dfs(int s,int u)
{
    if(u==1) return 1;
    if(vis[u]) return 0;
    vis[u]=1;
    for(int v=0;v<n;v++)
    {
        if(u==v) continue;
        if((cost[u][v]&s))
            if(dfs(s,v))
                return 1;
    }
    return 0;
}

int getcnt(int s)
{
    int i,cnt=0;
    for(i=0;i<k;i++)
        if(test(s,i))
            cnt++;
    return cnt;
}

void print(int s)
{
    for(int i=0;i<k;i++)
        if(test(s,i))
            printf("%d ",i);
    puts("");
}

void run()
{
    memset(cost,0,sizeof(cost));
    int u,v,w;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(u==v) continue;
        set(cost[u][v],w);
        set(cost[v][u],w);
    }
    int ans, anst = k+1;
    for(int i=1;i<(1<<k);i++)
    {
        memset(vis,0,sizeof(vis));
        int tmp = getcnt(i);
        if(tmp>=anst) continue;
        if(dfs(i,0))
        {
            anst = tmp;
            ans = i;
        }
    }
    printf("%d\n",anst);
    print(ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d%d",&k,&n,&m)!=EOF)
        run();
    return 0;
}
