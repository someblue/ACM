#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,n) for(i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 510;
int cas = 1;
//  http://vjudge.net/vjudge/contest/view.action?cid=54843#overview
//  http://www.bnuoj.com/bnuoj/contest_show.php?cid=4700
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
char g[N][N];
bool danger[N][N],vis[N][N];
int mia[N][N];
int cnt,num,n,m,k;
int lx,ly,rx,ry;
char c;

bool ok1(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}
void dfs1(int x,int y)
{
    lx = min(lx,x);
    ly = min(ly,y);
    rx = max(rx,x);
    ry = max(ry,y);
    vis[x][y]=1;
    mia[x][y]=num;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!mia[nx][ny] && ok1(nx,ny) && g[nx][ny]==c)
        {
            dfs1(nx,ny);
        }
    }
}

bool ok2(int x,int y)
{
    return ok1(x,y) && x>=lx && x<=rx && y>=ly && y<=ry;
}
void dfs2(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!vis[nx][ny] && ok2(nx,ny) && mia[nx][ny]!=num)
        {
            dfs2(nx,ny);
        }
    }
}
void show(int danger[N][N])
{
    cout<<"----"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%3d",danger[i][j]);
        cout<<endl;
    }
}

void run()
{
    memset(danger,0,sizeof(danger));
    memset(mia,0,sizeof(mia));
    cnt=num=0;
    for(int i=1;i<=n;i++)   scanf("%s",g[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mia[i][j]) continue;
            num++;
            cnt=0;
            c=g[i][j];
//            lx=rx=i,ly=ry=j;
            lx=ly=m+n;
            rx=ry=0;
            memset(vis,0,sizeof(vis));
            dfs1(i,j);
            if(cnt<k) continue;
            lx--,ly--;
            rx++,ry++;
            memset(vis,0,sizeof(vis));
            dfs2(lx,ly);
            for(int ii=lx;ii<=rx;ii++)
            for(int jj=ly;jj<=ry;jj++)
            if(!vis[ii][jj])
                danger[ii][jj]=1;
        }
    }
//    show(mia);
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(danger[i][j]) ans++;
    printf("%d\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
        run();
    return 0;
}
