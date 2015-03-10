#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define drep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 50005;
const int M = N<<1;
int cas = 1;

struct _edge {
    int to, next;
};
_edge edge[M];
int head[N], ecnt;
int n, k, kk;

void init()
{
    memset(head, -1, sizeof(head));
    ecnt = 0;
}
inline void add_edge(int u, int v)
{
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

int dp[N][510], sum[N][510];
bool vis[M];
ll ans;

int dfs(int u)
{
    for(int i=0; i<=k; i++)
    {
        dp[u][i] = 0;
        sum[u][i] = 0;
    }
    dp[u][0] = 1;
    int flag = 0;
    #ifdef LOCAL
    #endif // LOCAL
    for(int e=head[u]; e!=-1; e=edge[e].next)
    {
        if(vis[e]) continue;
        vis[e^1] = flag = 1;
        int &v = edge[e].to;
        dfs(v);
        for(int dep=0; dep<=k; dep++)
            sum[u][dep] += dp[v][dep];

        #ifdef LOCAL
//        printf("%d:%d sum:", u, v);
//        for(int dep=0; dep<=k; dep++)
//            printf("%d ", sum[u][dep]);
//        puts("");
        #endif // LOCAL
    }
    #ifdef LOCAL
    #endif // LOCAL
    if(!flag)
    {
        for(int i=1; i<=k; i++) dp[u][i] = 0;
        dp[u][0] = 1;
    }
    for(int dep=1; dep<=k; dep++)
    {
        dp[u][dep] = sum[u][dep-1];
    }
    ans += dp[u][k]; ll tmp = 0;
    for(int e=head[u]; e!=-1; e=edge[e].next)
    {
        if(vis[e]) continue;
        int &v = edge[e].to;
        for(int l=0; l<=k-2; l++)
        {
            tmp += dp[v][l] * (sum[u][k-2-l] - dp[v][k-2-l]);
        }
    }
    ans += tmp/2;
    return 1;
}

void dfs2(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    cout << u << ' ';
    for(int e=head[u]; e!=-1; e=edge[e].next)
        dfs2(edge[e].to);
}

void run()
{
    init();
    MS(vis);
    kk = k+1;
    int u,v;
    drep(i, 0, n-1)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    ans = 0;
    dfs(1);

//    drep(i, 1, n+1)
//    {
//        drep(j, 0, kk) cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d%d", &n, &k))
        run();
    return 0;
}
