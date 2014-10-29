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
#define N 8
#define REP(i,n) for(i=0;i<n;i++)
#define getz(x,y) ((x)*n+y)
using namespace std;
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;
const int  dx[]={-1,1,0,0};
const int  dy[]={0,0,-1,1};

bool g[N][N];
bool con_vis[N][N],bfs_vis[N][N][4];
int box_s,box_t,player_s;
int dep[N][N][4];
int m,n;

inline bool inside(int x, int y)
{
    return x>=0 && x<m && y>=0 && y<n;
}

inline void getxy(int &x, int &y, int &z)
{
    x=z/n;
    y=z%n;
}

bool con_dfs(int nowx,int nowy,int tx,int ty)
{
    if(nowx==tx && nowy==ty)    return 1;
    int i,x,y;
    REP(i,4)
    {
        x=nowx+dx[i];
        y=nowy+dy[i];
        if(!inside(x,y) || g[x][y] || con_vis[x][y])
            continue;
        con_vis[x][y]=1;
        if(con_dfs(x,y,tx,ty))    return 1;
    }
    return 0;
}

bool connect(int box,int sx,int sy,int tx, int ty)
{
    int box_x,box_y;
    getxy(box_x,box_y,box);
    if(!inside(sx,sy) || g[sx][sy] || !inside(tx,ty) || g[tx][ty])
    {
//        printf("(%d,%d) and (%d,%d)\n",sx,sy,tx,ty);
        return 0;
    }
    g[box_x][box_y]=1;
    memset(con_vis,0,sizeof(con_vis));
    int k=con_dfs(sx,sy,tx,ty);
    g[box_x][box_y]=0;
//    if(k)   printf("(%d,%d) to (%d,%d) connect\n",sx,sy,tx,ty);
    return k;
}

bool ok(int box, int olddir, int newdir)
{
    int x,y,newx,newy;
    getxy(x,y,box);
    newx = x+dx[newdir];
    newy = y+dy[newdir];
    if(bfs_vis[newx][newy][newdir]) {return 0;}
    if(!inside(newx,newy) || g[newx][newy]) {return 0;}
    if(olddir == newdir)    return 1;
    //cout<<"dir:"<<olddir<<' '<<newdir<<endl;
    return connect(box,x-dx[olddir],y-dy[olddir],x-dx[newdir],y-dy[newdir]);
}

bool ok2(int box,int plr,int dir)
{
    int x,y;
    getxy(x,y,box);
    int plrx,plry;
    getxy(plrx,plry,plr);
    int newx = x+dx[dir];
    int newy = y+dy[dir];
    int oldx = x-dx[dir];
    int oldy = y-dy[dir];
    if(!inside(newx,newy) || g[newx][newy]) return 0;
    if(!inside(oldx,oldy) || g[oldx][oldy]) return 0;
    return connect(box,plrx,plry,oldx,oldy);
}

int bfs()
{
    memset(bfs_vis,0,sizeof(bfs_vis));
    memset(dep,0,sizeof(dep));
    queue<pii> q;
    int i,x,y;
    getxy(x,y,box_s);
    for(i=0;i<4;i++)
        if(ok2(box_s,player_s,i))
        {
            //if(i==4)    cout<<"kaokaokao"<<endl;
            bfs_vis[x][y][i]=1;
            q.push(make_pair(box_s,i));
        }
    //cout<<"empty()?"<<q.empty()<<endl;
    while(!q.empty())
    {
        pii t=q.front();q.pop();
        int box=t.first;
        int dir=t.second;
        getxy(x,y,box);
        REP(i,4)
        {
//            printf("box=%d,dir=%d,i=%d\n",box,dir,i);
            if(!ok(box,dir,i))   continue;
            int newx = x+dx[i];
            int newy = y+dy[i];
            int newz = getz(newx,newy);
            if(newz==box_t) return dep[x][y][dir]+1;
            bfs_vis[newx][newy][i] = 1;
            dep[newx][newy][i] = dep[x][y][dir]+1;
            q.push(make_pair(newz,i));
//            printf("(%d,%d), from %d, to %d\n",x,y,dir,i);
        }
    }
    return -1;
}

void run()
{
    int i,j,k;
    memset(g,0,sizeof(g));
    cin>>m>>n;
    REP(i,m)
        REP(j,n)
        {
            cin>>k;
            if(k==0)    continue;
            else if(k==1)    g[i][j]=1;
            else if(k==2)    box_s = getz(i,j);
            else if(k==3)    box_t = getz(i,j);
            else             player_s = getz(i,j);
        }
    cout<<bfs()<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
        run();
    return 0;
}
