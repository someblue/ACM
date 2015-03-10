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
typedef pair<int,pii> piii; // dis, (u, use)
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
const int M = 100010;
int cas = 1;

struct _edge {
    int w, to, next;
};
_edge edge[M];
int head[N], ecnt;
int n, m, S, T;
int fa[N];
int d[N][2];
bool done[N][2];

inline void add_edge(int u, int v, int w) {
    edge[ecnt].to = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

inline void init() {
    ecnt = 0;
    drep(i, 1, n+1) fa[i] = i;
    drep(i, 1, n+1) d[i][0] = d[i][1] = INF;
    MS(done);
    memset(head, -1, sizeof(head));
}
inline int find(int x) {
    return fa[x]==x?x: fa[x]=find(fa[x]);
}

void dij(int s) {
    d[s][0] = 0;
    priority_queue<piii, vector<piii>, greater<piii> > que;
    que.push(piii(0, pii(s, 0)));
    while(!que.empty()) {
        piii t = que.top();
        que.pop();
        int u = t.se.fi, use = t.se.se;
        if(done[u][use]) continue;
        done[u][use] = 1;
        for(int e=head[u]; e!=-1; e=edge[e].next) {
            int &v = edge[e].to;
            if(use) {
                if(d[v][1] > d[u][1] + edge[e].w) {
                    d[v][1] = d[u][1] + edge[e].w;
                    que.push(piii(d[v][1], pii(v,1)));
                }
            } else {
                if(d[v][0] > d[u][0] + edge[e].w) {
                    d[v][0] = d[u][0] + edge[e].w;
                    que.push(piii(d[v][0], pii(v,0)));
                }
                if(d[v][1] > d[u][0] + edge[e].w/2) {
                    d[v][1] = d[u][0] + edge[e].w/2;
                    que.push(piii(d[v][1], pii(v,1)));
                }
            }
        }
    }
}

void run()
{
    scanf("%d%d%d%d", &n, &m, &S, &T);
    init();
    int u, v, w;
    drep(i, 0, m) {
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    dij(S);
    if(d[T][1] == INF && d[T][0] == INF) {
        puts("-1");
    } else {
        printf("%d\n", min(d[T][1], d[T][0]));
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
