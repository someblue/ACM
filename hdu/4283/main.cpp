#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N 105
#define REP(i,n) for(i=1;(i)<=(n);i++)
using namespace std;
const int INF=1<<25;
const double eps=1e-6;

int dp[N][N],a[N],sum[N],n;

void run()
{
    int _,cas=1;
    int i,j,k;
    scanf("%d",&_);
    while(_--)
    {
        cin>>n;
        sum[0]=0;
        REP(i,n)    cin>>a[i],sum[i]=sum[i-1]+a[i];
        REP(i,n)REP(j,n)    dp[i][j]=INF;
        REP(i,n)            dp[i][i]=0;
        for(int l=1;l<=n;l++)
        {
            for(i=1;i+l<=n;i++)
            {
                j=i+l;
                dp[i][j]=min(dp[i+1][j]+sum[j]-sum[i],(j-i)*a[i]+dp[i+1][j]);
                for(k=2;k<=j-i;k++)
                {
                    if(dp[i+1][i+k-1]==INF || dp[i+k][j]==INF)  cout<<"wrong"<<endl;
                    dp[i][j]=min(dp[i][j],dp[i+1][i+k-1]+ dp[i+k][j]+k*(sum[j]-sum[i+k-1]) + (k-1)*a[i]);
                }
            }
        }
        printf("Case #%d: %d\n",cas++,dp[1][n]);
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
