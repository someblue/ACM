#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define rep(i,l,r) for(i=(l);i<(r);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
const ll mod = 1e9+7;
int cas = 1;

struct Matrix {
    int n,m;
    ll a[N][N];
    Matrix (int _n, int _m) {
        n = _n, m = _m;
        MS(a);
    }
    ll* operator [] (int x) {
        return a[x];
    }
    const ll * operator[] (int x) const {
        return a[x];
    }
};

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix res(a.n, b.m);
    int i,j,k;
    rep(i, 0, a.n)
        rep(j, 0, a.m)
            rep(k, 0, b.m) {
                res[i][k] += a[i][j] * b[j][k] % mod;
                res[i][k] %= mod;
            }
    return res;
}

int n, x;
ll cnt[N], dp[N];

void run() {
    MS(cnt);
    MS(dp);
    int i,j,t;
    rep(i,0,n) {
        cin >> t;
        cnt[t]++;
    }
    Matrix a(1, 101), b(101, 101);
    ll sigma = dp[0] = cnt[0] = 1;
    rep(i, 1, 101) {
        for(j=1; i-j>=0; j++) {
            dp[i] += dp[i-j] * cnt[j] % mod;
            dp[i] %= mod;
        }
        sigma += dp[i];
    }
    if(x <= 100) {
        ll ans = 0;
        rep(i, 0, x+1) ans += dp[i], ans %= mod;
        cout << ans << endl;
        return;
    }
    rep(i, 0, 100) a[0][i] = dp[i+1];
    a[0][100] = sigma;
    rep(i, 0, 99) b[i+1][i] = 1;
    rep(i, 0, 100) b[i][99] = b[i][100] = cnt[100-i];
    b[100][100] = 1;

//    rep(i, 0, 101) {
//        rep(j, 0, 101) {
//            cout << b[i][j] << ' ';
//        }
//        cout << endl;
//    }

    t = x - 100;
    while(t) {
        if(t & 1) {
            a = a * b;
        }
        b = b * b;
        t >>= 1;
    }
    cout << a[0][100] << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>n>>x)
        run();
    return 0;
}
