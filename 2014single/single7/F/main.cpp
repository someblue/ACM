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
const int INF=1e9;
const double eps=1e-6;
const int N = 210;

int nx,ny;
int g[N][N];
int linker[N],lx[N],ly[N];// x is outpoint, y is inpoint
int slack[N];
int visx[N],visy[N];

int n,m;

bool DFS(int x)
{
    visx[x]=true;
    for(int y=0;y<ny;y++)
    {
        if(visy[y]) continue;
        int tmp = lx[x]+ly[y]-g[x][y];
        if(tmp==0)
        {
            visy[y]=true;
            if(linker[y]==-1||DFS(linker[y]))
            {
                linker[y]=x;
                return true;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
    }
    return false;
}

int KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<nx;i++)
    {
        lx[i]=-INF;
        for(int j=0;j<ny;j++)
            if(g[i][j]>lx[i])
                lx[i]=g[i][j];
    }
    for(int x=0;x<nx;x++)
    {
        for(int i=0;i<ny;i++)
            slack[i]=INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(DFS(x)) break;
            int d = INF;
            for(int i=0;i<ny;i++)
                if(!visy[i] && d>slack[i])
                    d=slack[i];
            for(int i=0;i<nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i=0;i<ny;i++)
            {
                if(visy[i]) ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res = 0, cnt = 0;
    for(int i=0;i<ny;i++)
    {
        if(linker[i]==-1 || g[linker[i]][i]==-INF)
            continue;
        res += g[linker[i]][i];
        cnt++;
    }
    if(cnt!=nx) return -1;
    return -res;
}

void run()
{
//    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=-INF;
    int u,v,c;
    while(m--)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&c);
        if(-c>g[u-1][v-1])
            g[u-1][v-1]=-c;
    }
    nx=ny=n;
    printf("%d\n",KM());
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif // LOCAL
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
