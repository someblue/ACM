#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105
using namespace std;

bool g[N][N],vis[N];
int n,m;
int k;
bool fir;

bool dfs(int x)
{
    if(!fir&&x==k)    return 0;
    if(fir) fir=0;
    for(int i=0;i<n;++i)
    {
        if(!vis[i] && g[x][i])
        {
            vis[i]=1;
            if(!dfs(i)) return 0;
        }
    }
    return 1;
}

void run()
{
    memset(g,0,sizeof(g));
    int i,a,b;
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        g[b][a]=1;
    }
    for(k=0;k<n;++k)
    {
        memset(vis,0,sizeof(vis));
        fir=1;
        if(!dfs(k)) break;
    }
    printf("%s\n",k<n?"NO":"YES");
}

int main()
{
    while(cin>>n>>m && n)
        run();
    return 0;
}
