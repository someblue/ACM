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
const int INF=1<<30;
const double eps=1e-6;

double dp[N*N],b[N];
int n,a[N];

void run()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int sum=0,i,j;
        double p;
        memset(dp,0,sizeof(dp));
        cin>>p>>n;
        REP(i,n)
        {
            cin>>a[i]>>b[i];
            sum+=a[i];
        }
        dp[0]=1.0;
        REP(i,n)
            for(j=sum;j>=a[i];j--)
            {
                dp[j]=max(dp[j],dp[j-a[i]]*(1.0-b[i]));
            }
        for(i=sum;i>=0;i--)
            if(dp[i]>=1.0-p)
            {
                cout<<i<<endl;
                break;
            }
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
