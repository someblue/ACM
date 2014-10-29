#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 1010
using namespace std;
typedef vector<int> VI;
typedef long long ll;
int fa[N];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void run()
{
    int n,m,u,v,ans;
    int i;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        scanf("%d",&m);
        ans = -1;
        for(i=1;i<=n;i++) fa[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            u = find(u); v = find(v);
            if(u!=v) fa[u]=v;
        }
        for(i=1;i<=n;i++)
            if(fa[i]==i) ans++;
        printf("%d\n",ans);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    run();
    return 0;
}
