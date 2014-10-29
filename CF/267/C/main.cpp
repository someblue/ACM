#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 5010;
int cas = 1;

#define MAX(x,y) ((x)>(y)?(x):(y))

ll dp[N][N];
ll p[N];
ll sum[N];
int n,m,k;

void run()
{
    int i,j;
    for(i=1;i<=n;i++)
        scanf("%I64d",&p[i]);
    memset(sum,0,sizeof(sum));
    for(i=1;i<=m;i++)
        sum[1]+=p[i];
    for(i=2;i+m-1<=n;i++)
        sum[i]=sum[i-1]-p[i-1]+p[i+m-1];
    memset(dp,-1,sizeof(dp));
    dp[0][0]=dp[1][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            dp[i][j]=MAX(dp[i][j],dp[i-1][j]);
            if(dp[i-1][j]!=-1 && i+m-1<=n)
                dp[i+m-1][j+1]=MAX(dp[i+m-1][j+1],dp[i-1][j]+sum[i]);
        }
    }
    ll ans = 0;
    for(i=1;i<=n;i++)
        ans = MAX(ans,dp[i][k]);
    printf("%I64d\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
        run();
    return 0;
}
