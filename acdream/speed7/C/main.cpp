#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 500;
int cas = 1;

int dp[N][N];
int ans;
int a[N],n;

void next()
{
    int i;
    int t=a[1];
    for(i=1;i<n;i++)
        a[i]=a[i+1];
    a[n]=t;
    a[n+1]=a[1];
}

void get_dp()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i+2<=2*n+1;i++)
        dp[i][i+1]=a[i]*a[i+1]*a[i+2];
    int t;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=2*n;i++)
        {
            int j=i+len;
            for(int k=i;k<j;k++)
            {
                t=dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];
                if(t>dp[i][j])
                    dp[i][j]=t;
            }
        }
    }
}

void run()
{
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    ans = 0;
    a[2*n+1]=a[1];
    get_dp();
    for(i=1;i+n-1<=2*n;i++)
        ans = max(ans,dp[i][i+n-1]);
    printf("%d\n",ans);
}

//void run()
//{
//    int i;
//    for(i=1;i<=n;i++)
//        scanf("%d",&a[i]);
//    ans = 0;
//    a[n+1]=a[1];
//    for(i=1;i<=n;i++)
//    {
//        get_dp();
//        if(ans<dp[1][n])
//            ans = dp[1][n];
//        next();
//    }
//    printf("%d\n",ans);
//}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
//    while(scanf("%d",&n)!=EOF)
    scanf("%d",&n);
        run();
    return 0;
}
