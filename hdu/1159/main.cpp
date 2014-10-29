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
#define N 1000
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

char a[N],b[N];
int dp[N][N];

void run()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int i,j;
        int la=strlen(a),lb=strlen(b);
        for(i=0;i<=la;i++)
            for(j=0;j<=lb;j++)
            {
                if(i==0||j==0)  dp[i][j]=0;
                else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        printf("%d\n",dp[la][lb]);
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
