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
const int INF=1<<30;
const double eps=1e-6;
const int N = 100010;

int fa[N],n,a[N];
vector<int> ans[N];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void run()
{
    for(int i=1;i<=n;i++)
    {
        fa[i] = i;
        ans[i].clear();
    }
    int u,v;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v);
        u = find(i);
        v = find(v);
        if(u>v) swap(u,v);
        fa[v]=u;
    }
    for(int i=1;i<=n;i++)
    {
        ans[find(i)].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]!=i) continue;
        printf("(");
        int sz = ans[i].size();
        printf("%d",ans[i][0]);
        for(int j=1;j<sz;j++)
            printf(" %d",ans[i][j]);
        printf(")");
    }
    puts("");
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
