#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 3010;
const int M = 30010;
int cas = 1;

struct _edge{
    int u,v;
}edge[M];

bool g[N][N];
int c[N][N];
int n,m;

void run()
{
    memset(g,0,sizeof(g));
    memset(c,0,sizeof(c));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&edge[i].u,&edge[i].v);
        g[edge[i].u][edge[i].v]=1;
    }
    for(int i=0;i<m;i++)
    {
        int &x=edge[i].u;
        int &y=edge[i].v;
        for(int z=1;z<=n;z++)
            if(z!=x && z!=y && g[z][x])
                c[z][y]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j && c[i][j])
                ans+=c[i][j]*(c[i][j]-1);
    printf("%d\n",ans/2);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
