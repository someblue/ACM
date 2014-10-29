#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 20;
int cas = 1;

char s[N];
int dp[N][N];

void run()
{
    int sz = strlen(s+1);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=sz;i++)
    {
        if(s[i]=='(' || s[i]=='?')
            for(int j=1;j<=sz;j++)
                dp[i][j]+=dp[i-1][j-1];
        if(s[i]==')' || s[i]=='?')
            for(int j=0;j<=sz;j++)
                dp[i][j]+=dp[i-1][j+1];
    }
    printf("%d\n",dp[sz][0]);
}

int main()
{
    #ifdef LOCAL
    //freopen("case.txt","r",stdin);
    #endif
    while(scanf("%s",s+1)!=EOF)
        run();
    return 0;
}
