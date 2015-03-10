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
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 105;
int cas = 1;

int g[N][N];
int g2[N][N];
int vis[N][N];
int n,m;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

inline bool inside(const int x, const int y) {return x>=1 && x<=n && y>=1 && y<=m;}
inline bool water_inside(const int x, const int y) {return x>=0 && x<=n+1 && y>=0 && y<=m+1;}

inline void dfs(int x, int y)
{
    if(vis[x][y] || !inside(x, y) || !g2[x][y]) return;
    vis[x][y] = 1;
    for(int i=0; i<4; i++)
        dfs(x+dx[i], y+dy[i]);
}

inline void water_dfs(int x, int y, int &h)
{
//    cout << x << ' ' << y << endl;
//    printf("%d %d %d\n", vis[x][y] , !water_inside(x, y) , g[x][y] > h);
    if(vis[x][y] || !water_inside(x, y) || g[x][y] > h) return;
    vis[x][y] = 1;
    g2[x][y] = 0;
    for(int i=0; i<4; i++)
        water_dfs(x+dx[i], y+dy[i], h);
}

inline int judge(int h)
{
    int i,j;
    for(i=0; i<=n+1; i++) for(j=0; j<=m+1; j++)
    {
        vis[i][j] = 0;
        g2[i][j] = 1;
    }
    water_dfs(0, 0, h);

//    printf("height=%d:\n", h);
//    rep(i, 1, n+1)
//    {
//        rep(j, 1, m+1) cout << g2[i][j] << ' ';
//        cout << endl;
//    }

    int cnt = 0;
    rep(i, 1, n+1) rep(j, 1, m+1) vis[i][j] = 0;
    rep(i, 1, n+1) rep(j, 1, m+1)
    {
        if(vis[i][j] || !g2[i][j]) continue;
        dfs(i, j); cnt++;
        if(cnt > 1) return 1;
    }
    return 0;
}

int binary(int l, int r)
{
    int mid, ans = -1;
    while(l<=r) {
        mid = (l+r)/2;
        if(judge(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

void run()
{
    int i,j,mx=0;
    rep(i, 1, n+1) rep(j, 1, m+1) {
        scanf("%d", &g[i][j]);
        if(mx < g[i][j]) mx=g[i][j];
    }
    i=0; for(j=0; j<=m+1; j++) g[i][j] = -1;
    j=0; for(i=0; i<=n+1; i++) g[i][j] = -1;
    i=n+1; for(j=0; j<=m+1; j++) g[i][j] = -1;
    j=m+1; for(i=0; i<=n+1; i++) g[i][j] = -1;

    int ans = binary(1, mx);
    printf("Case %d: ", cas++);
    if(ans == -1) puts("Island never splits.");
    else printf("Island splits when ocean rises %d feet.\n", ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d%d",&n,&m) && n)
        run();
    return 0;
}
