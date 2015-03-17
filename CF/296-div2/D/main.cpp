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

int val[N*2], n, ntwo;
pii p[N];
map<int, int> mp;
int c[N*2];

#define x first
#define w second
#define lowbit(x) (x&-x)
inline void add(int x) {
    while(x<=ntwo) {
        c[x]++; x+=lowbit(x);
    }
}
inline int sum(int x) {
    int ret=0;
    while(x>0) {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}


void run()
{
    ntwo = n*2;
    for(int i=0; i<n; i++) {
        scanf("%d%d",&p[i].x,&p[i].w);
        val[i<<1] = p[i].x-p[i].w;
        val[i<<1|1] = p[i].x+p[i].w;
    }
    sort(p, p+n);
    sort(val, val+ntwo);
    mp.clear();
    for(int i=0; i<ntwo; i++) {
        mp[val[i]] = i+1;
    }
    ll ans = 0;
    memset(c,0,sizeof(c));
    for(int i=0; i<n; i++) {
        ans += sum(mp[p[i].x-p[i].w]);
        printf("%d: query(%d):%d add(%d)\n", i, p[i].x-p[i].w,sum(mp[p[i].x-p[i].w]), p[i].x+p[i].w);
        add(mp[p[i].x+p[i].w]);
    }
    puts("");
    cout << ans << endl;
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
