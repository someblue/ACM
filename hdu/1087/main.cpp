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
#define N 1010
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
long long n,v[N],dp[N],ans;
void run()
{
    while(scanf("%lld",&n)!=EOF&&n!=0)
    {
        int i,j;
        for(i=0;i<n;i++) scanf("%lld",&v[i]);
        ans=0;
        for(i=0;i<n;i++)
        {
            long long tmp=0;
            for(j=0;j<i;j++)    if(v[i]>v[j])   tmp=max(tmp,dp[j]);
            dp[i]=tmp+v[i];
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
