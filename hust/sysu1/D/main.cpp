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
#define N 850
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
int n,m,d[N][N],md,mx,my;
char s[N];
bool vis[N][N];

struct _node{
    int v,d,x,y;
}g[N][N];

inline int max(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}

inline bool ok(int x,int y)
{
    return !(x<0||y<0||x>=n||y>=m||g[x][y].v||vis[x][y]);
}

int bfs(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m||g[x][y].v)   return 0;
    memset(vis,0,sizeof(vis));
    queue<_node> q;
    //g[x][y].v=1;
    vis[x][y]=1;
    g[x][y].d=1;
    q.push(g[x][y]);
    int res=0;
    while(!q.empty())
    {
        _node t=q.front();q.pop();
        if(g[t.x][t.y].d>md)    {md=g[t.x][t.y].d;mx=t.x;my=t.y;}
        res=max(res,t.d);
        if(ok(t.x-1,t.y))   {g[t.x-1][t.y].d=t.d+1;vis[t.x-1][t.y]=1;q.push(g[t.x-1][t.y]);}
        if(ok(t.x+1,t.y))   {g[t.x+1][t.y].d=t.d+1;vis[t.x+1][t.y]=1;q.push(g[t.x+1][t.y]);}
        if(ok(t.x,t.y-1))   {g[t.x][t.y-1].d=t.d+1;vis[t.x][t.y-1]=1;q.push(g[t.x][t.y-1]);}
        if(ok(t.x,t.y+1))   {g[t.x][t.y+1].d=t.d+1;vis[t.x][t.y+1]=1;q.push(g[t.x][t.y+1]);}
    }
    return res;
}

void run()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=0;j<strlen(s);j++)
            g[i][j].v=(s[j]=='#'?1:0),g[i][j].x=i,g[i][j].y=j;
    }
    int t;
    md=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)
        if(t=bfs(i,j))
            goto yes;
    yes:;
    printf("%d\n",bfs(mx,my)-1);
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
