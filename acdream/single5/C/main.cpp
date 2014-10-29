#include <bits/stdc++.h>
#define ff(a,b) if(a<b) a=b;
using namespace std;
const int N = 25;

int dp[N][N][N][N*N];
int arr[N],m,n;
char s[N];

inline int idx(const char &c)
{
    if(c=='A') return 0;
    else if(c=='C') return 1;
    else return 2;
}

void run()
{
    scanf("%d",&m);
    n=strlen(s);
    int nn=n*n;
    for(int i=0;i<n;++i)
        arr[i+1]=idx(s[i]);
    int cur,j,a,ac;
    memset(dp,0,sizeof(dp));
    for(cur=1;cur<=n;++cur)
    {
        for(j=0;j<m;++j)
        {
            for(a=0;a<=n;++a)
            {
                for(ac=0;ac<=nn;++ac)
                {
                    if(arr[cur]==0)
                    {
//                        dp[cur][j][a+1][ac]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j][a+1][ac],dp[cur-1][j][a][ac])
//                        dp[cur][j+1][a][ac+a]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j+1][a][ac+a],dp[cur-1][j][a][ac])
//                        dp[cur][j+1][a][ac]=dp[cur-1][j][a][ac]+ac;
                        ff(dp[cur][j+1][a][ac],dp[cur-1][j][a][ac]+ac)
                    }
                    else if(arr[cur]==1)
                    {
//                        dp[cur][j][a][ac+a]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j][a][ac+a],dp[cur-1][j][a][ac])
//                        dp[cur][j+1][a+1][ac]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j+1][a+1][ac],dp[cur-1][j][a][ac])
//                        dp[cur][j+1][a][ac]=dp[cur-1][j][a][ac]+ac;
                        ff(dp[cur][j+1][a][ac],dp[cur-1][j][a][ac]+ac)
                    }
                    else
                    {
//                        dp[cur][j][a][ac]=dp[cur-1][j][a][ac]+ac;
                        ff(dp[cur][j][a][ac],dp[cur-1][j][a][ac]+ac)
//                        dp[cur][j+1][a+1][ac]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j+1][a+1][ac],dp[cur-1][j][a][ac])
//                        dp[cur][j+1][a][ac+a]=dp[cur-1][j][a][ac];
                        ff(dp[cur][j+1][a][ac+a],dp[cur-1][j][a][ac])
                    }
                }
            }
        }
    }
    int ans=0;
    for(j=0;j<=m;++j)
        for(a=0;a<=n;++a)
            for(ac=0;ac<=nn;++ac)
                ff(ans,dp[n][m][a][ac])
    cout<<ans<<endl;
}

int main()
{
    while(scanf("%s",s)!=EOF)
        run();
    return 0;
}
