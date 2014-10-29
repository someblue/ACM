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
#define N 110
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
int m[N][N],n,ans;

void run()
{
    scanf("%d",&n);
    int i,j,k,t;
    for(i=1;i<=n;i++)
    {
        m[i][0]=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&t);
            m[i][j]=m[i][j-1]+t;
        }
    }
    ans=-INF;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            t=0;
            for(k=1;k<=n;k++)
            {
                if(t<0) t=m[k][j]-m[k][i];
                else t+=m[k][j]-m[k][i];
                ans=max(t,ans);
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
