#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 200010;
int cas = 1;

struct _node {
    int x, w, add, sub, ark, srk;
    bool operator < (const _node &b) const {
        return x<b.x;
    }
};
struct lisan {
    int val, idx, rk, type;
    bool operator < (const lisan &b) const {
        return val < b.val;
    }
};

_node p[N];
lisan li[N*2];
int dp[N], n;

inline int max(const int& a,const int& b) {return a<b?b:a;}
int mes[N<<3], M;
void update(int x, int v) {
    x+=M;
    if(mes[x]>=v) return;
    mes[x]=v;
    for(x>>=1; x; x>>=1) {
        mes[x] = max(mes[x<<1], mes[x<<1|1]);
    }
}
int query(int l, int r) {
    int res = 0;
    for(l=l+M-1, r=r+M+1; l^r^1; l>>=1, r>>=1) {
        if(~l&1) res=max(res,mes[l^1]);
        if(r&1)  res=max(res,mes[r^1]);
    }
    return res;
}

void run()
{
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &p[i].x, &p[i].w);
        p[i].add = p[i].x+p[i].w;
        p[i].sub = p[i].x-p[i].w;
    }
    sort(p+1, p+1+n);
    for(int i=1; i<=n; i++) {
        li[i*2].val = p[i].add;
        li[i*2].idx = i;
        li[i*2].type = 0;
        li[i*2+1].val = p[i].sub;
        li[i*2+1].idx = i;
        li[i*2+1].type = 1;
    }
    sort(li+1*2, li+(1+n)*2);
    li[1].val = li[2].val-1;
    for(int i=1*2; i<=n*2+1; i++) {
        if(li[i].val != li[i-1].val)
            li[i].rk = i;
        else li[i].rk = li[i-1].rk;
        if(!li[i].type) {
            p[li[i].idx].ark = li[i].rk;
        } else {
            p[li[i].idx].srk = li[i].rk;
        }
    }
//    for(int i=1; i<=n; i++) printf("%d: add=%d sub=%d ark=%d srk=%d\n", i, p[i].add, p[i].sub, p[i].ark, p[i].srk);
    memset(mes, 0, sizeof(mes));
    for(M=1;M<=li[n*2+1].rk+1;M<<=1);
    int mx = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = query(1, p[i].srk)+1;
        if(mx < dp[i]) mx = dp[i];
        update(p[i].ark, dp[i]);
    }
    printf("%d\n", mx);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d", &n)!=EOF)
        run();
    return 0;
}
