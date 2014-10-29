#include <cstdio>
#include <cstring>
#include <iostream>
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
typedef long long ll;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 11;
int cas = 1;

int w[N];
struct _node{
    int u,v;
}e[N];
bool g[N][N],vis[N];
int n,m;

int dfs(int u)
{
    vis[u]=1;
    int ret = 0;
    for(int v=0;v<n;v++)
        if(g[u][v] && !vis[v])
            ret += dfs(v);
    return ret + w[u];
}

void run()
{
    for(int i=0;i<n;i++) scanf("%d",w+i);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&e[i].u,&e[i].v);
        e[i].u--; e[i].v--;
    }
    int ans = INF;
    for(int st=1;st<(1<<m);st++)
    {
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
            if(st&(1<<i))
                g[e[i].u][e[i].v]=g[e[i].v][e[i].u]=1;
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        int sum[2];
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
//            if(cnt>=2) break;
            sum[cnt++] = dfs(i);
        }
//        cout<<st<<' '<<cnt<<' '<<sum[0]<<' '<<sum[1]<<endl;
        if(cnt!=2) continue;
        if(ans > abs(sum[0]-sum[1]))
            ans = abs(sum[0]-sum[1]);
    }
    printf("%d\n",ans);
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
