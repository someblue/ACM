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
#define MS2(x) memset(x,-1,sizeof(x))
#define CLEAR(x) while(!x.empty()) x.pop();
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define rep2(i,l,r) for(i=(l);i<=(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define per2(i,l,r) for(i=(r);i>=l;i--)
#define drep(i,l,r) for(int i=(l);i<(r);i++)
#define drep2(i,l,r) for(int i=(l);i<=(r);i++)
#define dper(i,l,r) for(int i=(r)-1;i>=l;i--)
#define dper2(i,l,r) for(int i=(r);i>=l;i--)
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define MAX2(a,b) if(a<(b)) a=(b);
#define MIN2(a,b) if(a>(b)) a=(b);
#define SI(x) scanf("%d",&x)
#define SII(x,y) scanf("%d%d",&x,&y)
#define SIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SS(x) scanf("%s",x)
#define SSS(x,y) scanf("s",x,y)
#define PI(x) printf("%d",x)
#define PS(x) printf("%s",x)
#define PN puts("")
#define fi first
#define se second
#define IT iterator
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

int n, m, k;
int g[N][N], up[N][N];
int l[N][N], r[N][N], ans;
int c[N][N], d[N][N];

void run() {
    int x, y;
    drep2(i, 1, n) drep2(j, 1, m) g[i][j]=1;
    drep(i, 0, k) {
        SII(x,y);
        g[x][y] = 0;
    }
    drep2(i, 1, n) {
        drep2(j, 1, m) {
            if(!i || !g[i][j]) {
                up[i][j] = 0;
            } else {
                up[i][j] = up[i-1][j] + 1;
            }
        }
        drep2(j, 1, m) {
            l[i][j] = j-1;
            while(l[i][j]>0 && up[i][l[i][j]]>=up[i][j])
                l[i][j] = l[i][l[i][j]];
        }
        dper2(j, 1, m) {
            r[i][j] = j+1;
            while(r[i][j]<=m && up[i][r[i][j]]>=up[i][j])
                r[i][j] = r[i][r[i][j]];
        }
    }
    drep2(i, 1, n) drep2(j, 1, m) l[i][j]++, r[i][j]--;
    drep2(i, 1, n) drep2(j, 1, m) {
        MAX2(c[i-up[i][j]+1][i], r[i][j]-l[i][j]+1);
    }
    for(int len = n; len>=2; len--) {
        for(int i=1; i+len-1<=n; i++) {
            int j = i+len-1;
            MAX2(c[i+1][j],c[i][j]);
            MAX2(c[i][j-1],c[i][j]);
        }
    }
    MS(d);
    for(int len = 1; len<=n; len++) {
        for(int i=1; i+len-1<=n; i++) {
            int j = i+len-1;
            MAX2(d[i][j], c[i][j]*len);
            MAX2(d[i][j], d[i+1][j]);
            MAX2(d[i][j], d[i][j-1]);
        }
    }
    SI(k);
    while(k--) {
        SII(x,y);
        PI(d[x][y]);PN;
    }
}

int main() {
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~SIII(n,m,k)) {
        run();
    }
    return 0;
}
