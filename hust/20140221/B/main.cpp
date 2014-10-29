#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1010

using namespace std;

int dp[N],num[N];

int main()
{
    int n,i,j,maxsum;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            dp[i]=num[i];
            for(j=0;j<i;j++)
            {
                if(num[j]<num[i])
                {
                    dp[i]=max(dp[i],dp[j]+num[i]);
                }
            }
        }
        maxsum=dp[0];
        for(i=1;i<n;i++)
            if(maxsum<dp[i])
                maxsum=dp[i];
        printf("%d\n",maxsum);
    }
    return 0;
}
