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
#define N 12
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

int dp[N][N];

void run()
{
    int n;
    while(cin>>n&&n!=-1)
    {
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        int i,j;
        for(i=2;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*j;
        int ans=0;
        for(i=1;i<=n;i++)   ans+=dp[n][i];
        cout<<ans<<endl;
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
