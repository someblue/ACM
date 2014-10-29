#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define VI vector<int>
#define N 100010
typedef long long ll;
using namespace std;
int s[2][N],dp[N];
void run()
{
    int _;
    int n,i;
    scanf("%d",&_);
    while(_--)
    {
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[1][i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[0][i]);
        }
        dp[0]=s[0][0];
        dp[1]=dp[0]+s[0][1];
        dp[2]=dp[1]+s[0][2];
        for(i=3;i<=n+1;i++)
        {
            dp[i]=max(dp[i-3]+s[1][i-2]+s[1][i-1]+s[0][i],dp[i-1]+s[0][i]);
        }
        printf("%d\n",dp[n+1]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    run();
    return 0;
}
