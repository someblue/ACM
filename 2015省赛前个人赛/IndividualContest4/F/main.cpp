#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define drep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 200010;
const int M = N<<1;
int cas = 1;

struct _edge {
    int u, v;
    ll w;
    friend bool operator < (const _edge &a, const _edge &b)
    {
        return a.w > b.w;
    }
};
int n;
_edge e[N];
int fa[N];
int num[N];
ll weight[N];

inline int find(int x)
{
    return fa[x]==x? x: fa[x]=find(fa[x]);
}

void run()
{
    int u,v;
    drep(i, 0, n-1)
    {
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e, e+n-1);
    drep(i, 1, n+1)
        fa[i] = i, num[i] = 1, weight[i] = 0;
    drep(i, 0, n-1)
    {
        u = find(e[i].u);
        v = find(e[i].v);
        if(u!=v)
        {
            if(weight[u]+e[i].w*num[v] > weight[v]+e[i].w*num[u]) {
                fa[v] = u;
                num[u] += num[v];
                weight[u] += e[i].w*num[v];
            } else {
                fa[u] = v;
                num[v] += num[u];
                weight[v] += e[i].w*num[u];
            }
        }
    }
    printf("%lld\n", weight[find(1)]);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d", &n))
        run();
    return 0;
}
