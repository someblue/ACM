#include <iostream>
#include <cstdio>
#include <memory.h>
#define MIN(a , b) ((a) < (b) ? (a) : (b))
#define MAX(a  ,b) ((a) > (b) ? (a) : (b))
using namespace std;
const int maxn = 502;
const int move[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char map[maxn][maxn];
int hei[maxn][maxn];
bool vis[maxn][maxn],danger[maxn][maxn];
int lx,ly,rx,ry,m,n,k,num,cnt;

void init()
{
    memset(hei,-1,sizeof(hei));
    memset(danger,false,sizeof(danger));
    num = 0;
    return;
}

void read()
{
    for(int i=1;i<=m;i++)
    {
        scanf("%s",map[i]+1);
    }
    return;
}

bool judge(int x,int y)
{
    if(x > 0 && y > 0 && x <= m && y <= n)
    {
        return true;
    }
    return false;
}

void dfs(int x,int y,char c)
{
    lx = MIN(lx , x);
    ly = MIN(ly , y);
    rx = MAX(rx , x);
    ry = MAX(ry , y);
    hei[x][y] = num;
    cnt++;
    for(int i=0;i<4;i++)
    {
        int tx = x + move[i][0];
        int ty = y + move[i][1];
        if(judge(tx , ty) && map[tx][ty] == c && hei[tx][ty] == -1)
        {
            dfs(tx , ty , c);
        }
    }
    return;
}

bool check(int x,int y)
{
    if(x >= lx && x <= rx && y >= ly && y <= ry)
    {
        return true;
    }
    return false;
}

void DFS(int x,int y)
{
    vis[x][y] = true;
    for(int i=0;i<4;i++)
    {
        int tx = x + move[i][0];
        int ty = y + move[i][1];
        if(check(tx , ty) && vis[tx][ty] == false && hei[tx][ty] != num)
        {
            DFS(tx , ty);
        }
    }
    return;
}
void show(bool danger[maxn][maxn])
{
    cout<<"----"<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<danger[i][j]<<' ';
        cout<<endl;
    }
}
void solve()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(hei[i][j] == -1)
            {
                lx = ly = m+n;
                rx = ry = cnt = 0;
                dfs(i , j , map[i][j]);
                if(cnt < k)
                {
                    num++;
                    continue;
                }
                lx--;
                ly--;
                rx++;
                ry++;
                memset(vis,false,sizeof(vis));
                DFS(lx , ly);
//                cout<<"vis"<<endl;
//                show(vis);
                for(int i=lx+1;i<rx;i++)
                {
                    for(int j=ly+1;j<ry;j++)
                    {
                        if(vis[i][j] == false)
                        {
                            danger[i][j] = true;
                        }
                    }
                }
//                show(danger);
                num++;
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(danger[i][j]) sum++;
        }
    }
//    show(danger);
    printf("%d\n",sum);
    return;
}

int main()
{
    freopen("case.txt","r",stdin);
    while(~scanf("%d %d %d",&m,&n,&k))
    {
        init();
        read();
        solve();
    }
    return 0;
}
