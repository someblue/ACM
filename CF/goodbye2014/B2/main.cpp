#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 310;
int cas = 1;

int n;
int p[N];
char g[N][N];
int fa[N];
int vec[N][N],cnt[N];

int find(int x)
{
    return fa[x]==x? x: fa[x]=find(fa[x]);
}

void run()
{
    memset(g,0,sizeof(g));
    for(int i=1; i<=n; i++) fa[i]=i;
    for(int i=1; i<=n; i++) scanf("%d",p+i);
    for(int i=1; i<=n; i++)
        scanf("%s",g[i]+1);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(g[i][j]=='0') continue;
            int u = find(i);
            int v = find(j);
            if(u!=v)
                fa[u] = v;
        }
    for(int i=1; i<=n; i++) fa[i] = find(i);
    memset(cnt,0,sizeof(cnt));
//    for(int i=1; i<=n; i++) printf("%d ",fa[i]);
//    printf("\n");
    for(int i=1; i<=n; i++)
    {
        vec[fa[i]][cnt[fa[i]]++] = p[i];
    }
    for(int i=1; i<=n; i++)
        if(fa[i]==i)
            sort(vec[i],vec[i]+cnt[i]);
    memset(cnt,0,sizeof(cnt));
    for(int i=1; i<=n; i++)
        p[i] = vec[fa[i]][cnt[fa[i]]++];
    printf("%d",p[1]);
    for(int i=2; i<=n; i++) printf(" %d",p[i]);
    printf("\n");

}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
