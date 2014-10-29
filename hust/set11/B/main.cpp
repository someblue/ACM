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
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;
const int N = 100010;

int n,m;
double dp[N];
int fly[N];

void run()
{
    int i,j;
    int a,b;
    for(i=n+6;i>=n;--i) dp[i]=0.0;
    memset(fly,-1,sizeof(fly));
    while(m--)
    {
        scanf("%d%d",&a,&b);
        fly[a] = b;
    }
    for(i=n-1;i>=0;--i)
    {
        if(fly[i]!=-1)
        {
            dp[i] = dp[fly[i]];
            continue;
        }
        dp[i]=1.0;
        for(j=1;j<=6;++j)
            dp[i]+=dp[i+j]/6.0;
    }
    printf("%.4lf\n",dp[0]);
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF && n)
        run();
    return 0;
}
