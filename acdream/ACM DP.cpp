#include <bits/stdc++.h>
using namespace std;
 
int dp[22][22][22][220];
void update(int &x,int y)
{
    x = max(x,y);
}
 
int main()
{
    //freopen("acm.in","r",stdin);
    //freopen("acm.out","w",stdout);
    char s[25];
    while(scanf("%s",s + 1) != EOF) {
        int n = strlen(s + 1),m;
        scanf("%d",&m);
        m = min(m,n);
        for(int i = 0; i < 22; i ++)
            for(int j = 0; j < 22; j ++)
                for(int k = 0; k < 22; k ++)
                    for(int r = 0; r < 220; r ++)
                        dp[i][j][k][r] = -10000000;
        dp[0][0][0][0] = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j <= m; j ++)
                for(int k = 0; k <= i; k ++) {
                    int x = i * (i - 1) / 2;
                    for(int r = 0; r <= x; r ++) {
                        if(dp[i][j][k][r] < 0) continue;
                        //not change
                        if(s[i + 1] == 'M') update(dp[i + 1][j][k][r],dp[i][j][k][r] + r);
                        else if(s[i + 1] == 'A') update(dp[i + 1][j][k + 1][r],dp[i][j][k][r]);
                        else update(dp[i + 1][j][k][k + r],dp[i][j][k][r]);
                         
                        //change
                        if(j == m) continue;
                        update(dp[i + 1][j + 1][k][r],dp[i][j][k][r] + r);//M
                        update(dp[i + 1][j + 1][k + 1][r],dp[i][j][k][r]); //A
                        update(dp[i + 1][j + 1][k][k + r],dp[i][j][k][r]);//C                   
                    }
                }      
        int ans = 0;
        for(int i = 0; i <= m; i ++)
           for(int j = 0; j <= 20; j ++)
              for(int k = 0; k <= 200; k ++)
                  ans = max(ans,dp[n][i][j][k]);
        printf("%d\n",ans);
    }
    return 0;
}

