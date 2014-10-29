#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int g[N][N],w[N][N];
int dep[N][N],exitdep;
bool vis[N][N];
int n,m;
int enx,eny,exx,exy;
int ans;

inline bool inside(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs()
{
    exitdep = INF;
    ans = 0;
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    queue<pii> que;
    vis[enx][eny]=1;
    que.push(make_pair(enx,eny));
    dep[enx][eny]=0;
    w[enx][eny]=g[enx][eny];
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if(dep[x][y]>exitdep) continue;
        if(x==exx && y==exy)
        {
            //ans = max(ans,w[x][y]);
            exitdep = dep[x][y];
        }
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!vis[nx][ny] || dep[nx][ny]==dep[x][y]+1)
                w[nx][ny]=max(w[nx][ny],w[x][y]+g[nx][ny]);
            if(vis[nx][ny] || g[nx][ny]==-1 || !inside(nx,ny)) continue;
            vis[nx][ny]=1;
            dep[nx][ny]=dep[x][y]+1;
            que.push(make_pair(nx,ny));
        }
    }
}

void run()
{
    scanf("%d%d",&n,&m);
    int i,j;
    scanf("%d%d%d%d",&enx,&eny,&exx,&exy);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&g[i][j]);
    bfs();
    printf("Case #%d: ",cas++);
    if(exitdep==INF) puts("Mission Impossible.");
    else printf("%d\n",w[exx][exy]);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
