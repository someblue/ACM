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
using namespace std;
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;
const int N = 70;

ll dp[N][5];
ll a[N],len;

void init()
{
    dp[1][1]=1;
    dp[1][0]=9;
    dp[1][1]=1;
    dp[1][2]=0;
    for(int i=2;i<N;++i)
    {
        dp[i][0]=9*dp[i-1][0]+8*dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        dp[i][2]=10*dp[i-1][2]+dp[i-1][1];
    }
}

ll solve(ll x)
{
    len = 0;
    for(;x;x/=10)
        a[++len]=x%10;
    bool flag=0;
    ll ans=0;
    for(int i=len;i>0;--i)
    {
        for(int j=0;j<10;++j)
        {
            ans+=a[i]*dp[i-1][2];
            if(flag)    ans+=a[i]*dp[i-1][0];
        }
    }
    return 0;
}

void run()
{
    ll x;
    scanf("%I64d",&x);
}

int main()
{
//    freopen("case.txt","r",stdin);
    init();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
