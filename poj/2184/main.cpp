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
#define REP(i,n) for(i=0;(i)<(n);i++)
using namespace std;
const double eps=1e-6;

const int pos=100000;
const int INF=(1<<30);

int dp[pos*2+10],n;
int v[N],w[N];

int main()
{
//    freopen("case.txt","r",stdin);
    int i,j;
    cin>>n;
    REP(i,n)    cin>>v[i]>>w[i];
    for(i=0;i<=2*pos;i++)   dp[i]=-INF;
    dp[pos]=0;
    REP(i,n)
    {
        if(v[i]>=0)
        {
            for(j=2*pos;j>=v[i];j--)
                if(dp[j-v[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
        else
        {
            for(j=0;j<=2*pos+v[i];j++)
                if(dp[j-v[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    int ans=0;
    for(i=pos;i<=2*pos;i++)
        if(dp[i]>=0 && dp[i]+i-pos>ans)
            ans=dp[i]+i-pos;
    cout<<ans<<endl;
    return 0;
}
