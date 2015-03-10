#include <bits/stdc++.h>
#define REP(i,n) for(i=0; i<(n); i++)
#define FOR(i,n) for(i=1; i<=(n); i++)
#define REP2(i,a,b) for(i=(a);i<(b);i++)
#define FOR2(i,a,b) for(i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 5010;
int cas = 1;

int n,T,t[N];
double p[N],dp[2][N],ans;
double pass[N];

void work()
{
    dp[0][0] = 1.0;
    memset(pass,0,sizeof(pass));
    int now = 0;
    pass[now] = 1.0;
    for(int i=1; i<=n; i++)
    {
        now ^= 1;
        dp[now][0] = 0;
        double qq = 1.0;
        for(int k=1; k<=t[i]; k++) qq*=(1-p[i]);
        for(int j=0; j<T; j++)
        {
            dp[now][j+1] = dp[now][j]*(1-p[i]) + dp[!now][j]*p[i];
            if(j-t[i]>=0)
                dp[now][j+1] -= dp[!now][j-t[i]]*qq;
            if(j-t[i]+1>=0)
                dp[now][j+1] += dp[!now][j-t[i]+1]*qq;
            pass[now] += dp[now][j+1];
        }
        ans += (pass[!now] - pass[now]) * (i-1);
    }
    ans += n*pass[!now];
}

void run()
{
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        cin >> p[i] >> t[i];
        p[i] /= 100;
    }
    ans = 0.0;
    work();
//    for(int i=1; i<=n; i++)
//        ans += i*(pass[i] - pass[i+1]);
    printf("%.9f\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin >> n >> T)
        run();
    return 0;
}
