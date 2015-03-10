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
const int N = 2010;
int cas = 1;

int n, m;
int g[N][N], up[N][N];
int l[N], ans;


void run() {
    stack<pii> stk; ans = 0;
    drep(i, 0, n) drep(j, 0, n) {
        SI(g[i][j]);
    }
    drep(i, 0, n) {
        drep(j, 0, n) {
            if(!i || !g[i][j]) {
                up[i][j] = 0;
            } else {
                up[i][j] = up[i-1][j] + 1;
            }
        }
        CLEAR(stk);
        drep(j, 0, n) {
            while(!stk.empty() && up[i][j]<=stk.top().fi) {
                stk.pop();
            }
            if(stk.empty()) {
                l[j] = 0;
            } else {
                l[j] = stk.top().se + 1;
            }
            stk.push(pii(up[i][j], j));
        }
        CLEAR(stk);
        dper(j, 0, n) {
            while(!stk.empty() && up[i][j]<=stk.top().fi) {
                stk.pop();
            }
            if(stk.empty()) {
                MAX2(ans, up[i][j]*(n-1-l[j]+1));
            } else {
                MAX2(ans, up[i][j]*(stk.top().se-l[j]));
            }
            stk.push(pii(up[i][j], j));
        }
    }
    PI(ans);PN;
}

int main() {
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~SII(n,m)) {
        run();
    }
    return 0;
}

