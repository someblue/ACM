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
const int INF=1<<30;
const double eps=1e-9;
const int N = 1005;

double dp[N][N];

void run(int a,int b)
{
    int i,j;
    for(i=1;i<=a;++i)   dp[i][0]=1.0;
    for(j=0;j<=b;++j)   dp[0][j]=0.0;
    for(i=1;i<=a;++i)
        for(j=1;j<=b;++j)
        {
            double ii = i*1.0;
            double jj = j*1.0;
            dp[i][j] = ii/(ii+jj);
            if(j>=2)
                dp[i][j]+= jj/(ii+jj)*(jj-1)/(ii+jj-1)*ii/(ii+jj-2)*dp[i-1][j-2];
            if(j>=3)
                dp[i][j]+= jj/(ii+jj)*(jj-1)/(ii+jj-1)*(jj-2)/(ii+jj-2)*dp[i][j-3];
        }
    printf("%.9lf\n",dp[a][b]);
}

int main()
{
//    freopen("case.txt","r",stdin);
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
        run(a,b);
    return 0;
}
